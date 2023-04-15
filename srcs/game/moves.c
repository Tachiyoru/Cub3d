/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:12:10 by sleon             #+#    #+#             */
/*   Updated: 2023/04/15 16:27:22 by msharifi         ###   ########.fr       */
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
		if (d->map.map[(int)(d->ray.pos[Y] + d->ray.dir[Y] * 0.2)][(int)new[X]]
			== '1')
			return ;
	}
	else if (c == 'S')
		new[X] = ((new[Y] = d->ray.pos[Y] - (d->player_speed * d->ray.dir[Y]),
					d->ray.pos[X] - (d->player_speed * d->ray.dir[X])));
	else if (c == 'A')
		new[X] = ((new[Y] = d->ray.pos[Y] - (d->player_speed * d->ray.dir[X]),
					d->ray.pos[X] + (d->player_speed * d->ray.dir[Y])));
	else if (c == 'D')
		new[X] = ((new[Y] = d->ray.pos[Y] + (d->player_speed * d->ray.dir[X]),
					d->ray.pos[X] - (d->player_speed * d->ray.dir[Y])));
	if (d->map.map[(int)new[Y]][(int)new[X]] == '1')
		return ;
	update_pos(d, new);
	return ;
}

void	update_pos(t_data *data, double newpos[2])
{
	data->player[POS_X] = newpos[X];
	data->player[POS_Y] = newpos[Y];
	data->ray.pos[X] = newpos[X];
	data->ray.pos[Y] = newpos[Y];
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
