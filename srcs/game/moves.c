/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:12:10 by sleon             #+#    #+#             */
/*   Updated: 2023/04/12 17:17:50 by msharifi         ###   ########.fr       */
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

void	move_player(t_data *data, char c)
{
	double	newpos[2];

	if (c == 'W')
		newpos[X] = ((newpos[Y] = data->ray.pos[Y] + (data->player_speed * data->ray.dir[Y]),
					data->ray.pos[X] + (data->player_speed * data->ray.dir[X])));
	else if (c == 'S')
		newpos[X] = ((newpos[Y] = data->ray.pos[Y] - (data->player_speed * data->ray.dir[Y]),
					data->ray.pos[X] - (data->player_speed * data->ray.dir[X])));
	else if (c == 'A')
		newpos[X] = ((newpos[Y] = data->ray.pos[Y] - (data->player_speed * data->ray.dir[X]),
					data->ray.pos[X] + (data->player_speed * data->ray.dir[Y])));
	else if (c == 'D')
		newpos[X] = ((newpos[Y] = data->ray.pos[Y] + (data->player_speed * data->ray.dir[X]),
					data->ray.pos[X] - (data->player_speed * data->ray.dir[Y])));
	if (data->map.map[(int)newpos[Y]][(int)newpos[X]] == '1')
		return ;
	data->player[POS_X] = newpos[X];
	data->player[POS_Y] = newpos[Y];
	data->ray.pos[X] = newpos[X];
	data->ray.pos[Y] = newpos[Y];
	return ;
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
