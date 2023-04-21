/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:12:10 by sleon             #+#    #+#             */
/*   Updated: 2023/04/21 15:02:37 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_cam(t_data *data, double mouv)
{
	double	save_dir;
	double	save_plan;

	save_dir = data->ray.dir[X];
	save_plan = data->ray.plan[X];
	data->ray.dir[X] = data->ray.dir[X] * cos(mouv)
		- data->ray.dir[Y] * sin(mouv);
	data->ray.dir[Y] = save_dir * sin(mouv) + data->ray.dir[Y] * cos(mouv);
	data->ray.plan[X] = data->ray.plan[X] * cos(mouv)
		- data->ray.plan[Y] * sin(mouv);
	data->ray.plan[Y] = save_plan * sin(mouv) + data->ray.plan[Y] * cos(mouv);
}

void	move_player(t_data *d, char c)
{
	double	new[2];

	if (c == 'W')
	{
		new[X] = ((new[Y] = d->ray.pos[Y] + (d->player_speed * d->ray.dir[Y]),
					d->ray.pos[X] + (d->player_speed * d->ray.dir[X])));
		if (wall_or_door_too_close(d, new, c))
			return ;
	}
	else if (c == 'S')
	{
		new[X] = ((new[Y] = d->ray.pos[Y] - (d->player_speed * d->ray.dir[Y]),
					d->ray.pos[X] - (d->player_speed * d->ray.dir[X])));
		if (wall_or_door_too_close(d, new, c))
			return ;
	}
	if (move_player2(d, new, c))
		return ;
	if (d->map.map[(int)new[Y]][(int)new[X]] == '1'
		|| d->map.map[(int)new[Y]][(int)new[X]] == 'D')
		return ;
	update_pos(d, new);
	return ;
}

int	move_player2(t_data *d, double new[2], char c)
{
	if (c == 'A')
	{
		new[X] = ((new[Y] = d->ray.pos[Y] - (d->player_speed * d->ray.dir[X]),
					d->ray.pos[X] + (d->player_speed * d->ray.dir[Y])));
		if (wall_or_door_too_close(d, new, c))
			return (1);
	}
	else if (c == 'D')
	{
		new[X] = ((new[Y] = d->ray.pos[Y] + (d->player_speed * d->ray.dir[X]),
					d->ray.pos[X] - (d->player_speed * d->ray.dir[Y])));
		if (wall_or_door_too_close(d, new, c))
			return (1);
	}
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	double	diff;

	(void)y;
	if (data->mouse_pos == 10000)
	{
		data->mouse_pos = x;
		return (0);
	}
	diff = (data->mouse_pos - x) * 0.008;
	move_cam(data, -diff);
	data->mouse_pos = x;
	return (0);
}
