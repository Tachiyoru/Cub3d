/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:12:10 by sleon             #+#    #+#             */
/*   Updated: 2023/04/12 15:36:18 by msharifi         ###   ########.fr       */
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
		newpos[X] = ((newpos[Y] = data->ray.pos[Y] + (0.03 * data->ray.dir[Y]),
					data->ray.pos[X] + (0.03 * data->ray.dir[X])));
	else if (c == 'S')
		newpos[X] = ((newpos[Y] = data->ray.pos[Y] - (0.03 * data->ray.dir[Y]),
					data->ray.pos[X] - (0.03 * data->ray.dir[X])));
	else if (c == 'A')
		newpos[X] = ((newpos[Y] = data->ray.pos[Y] - (0.03 * data->ray.dir[X]),
					data->ray.pos[X] + (0.03 * data->ray.dir[Y])));
	else if (c == 'D')
		newpos[X] = ((newpos[Y] = data->ray.pos[Y] + (0.03 * data->ray.dir[X]),
					data->ray.pos[X] - (0.03 * data->ray.dir[Y])));
	if (data->map.map[(int)newpos[Y]][(int)newpos[X]] == '1')
		return ;
	data->player[POS_X] = newpos[X];
	data->player[POS_Y] = newpos[Y];
	data->ray.pos[X] = newpos[X];
	data->ray.pos[Y] = newpos[Y];
	return ;
}

int mouse_move(int x, int y, t_data *data)
{
	printf("y : %d	|	x : 5%d\n", y, x);

	// Mettre à jour la position de la caméra en fonction du mouvement de la souris
	int mouse_pos_x = x - data->ray.dir[X];
	// int mouse_pos_y = y - data->ray.dir[Y];
	int	diff_x = mouse_pos_x - (int)data->ray.dir[X] - x;
	// int	diff_y = mouse_pos_y - (int)data->ray.dir[Y] - y;
	// int cam_speed = 5; // Vitesse de déplacement de la caméra
	// int cam_pos_x = 0; // Position initiale de la caméra
	// int cam_pos_y = 0;

	if (diff_x < 0)
		data->ray.dir[X] -= (float)0.1;
	else if (diff_x > 0)
		data->ray.dir[X] += (float)0.1;
	// if (diff_y < 0)
	// 	data->ray.dir[y] -= (float)0.1;
	// else if (diff_y > 0)
	// 	data->ray.dir[y] += (float)0.1;
	// data->ray.raydir[X] = x;
	// data->ray.raydir[Y] = y;
	return 0;
}