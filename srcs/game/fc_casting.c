/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:33:51 by sleon             #+#    #+#             */
/*   Updated: 2023/04/15 13:57:51 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief first part of floor/ceiling casting, find the camera position,
 * then the distance from the floor, then according to the vector
 * calculate the steps and the coordinates of the floor from y
 *
 * @param data
 * @param y
 */
void	floor_ceiling_casting(t_data *data, int y)
{
	float	raydir[2][2];
	int		cam_pos;
	float	rowdistance;
	float	floorstep[2];
	float	floor[2];

	raydir[X][0] = data->ray.dir[X] - data->ray.plan[X];
	raydir[Y][0] = data->ray.dir[Y] - data->ray.plan[Y];
	raydir[X][1] = data->ray.dir[X] + data->ray.plan[X];
	raydir[Y][1] = data->ray.dir[Y] + data->ray.plan[Y];
	cam_pos = y - SCREEN_HEIGHT / 2;
	data->ray.cam_x = 0.5 * SCREEN_HEIGHT;
	rowdistance = data->ray.cam_x / cam_pos;
	floorstep[X] = rowdistance * (raydir[X][1] - raydir[X][0]) / SCREEN_WIDTH;
	floorstep[Y] = rowdistance * (raydir[Y][1] - raydir[Y][0]) / SCREEN_WIDTH;
	floor[X] = data->player[POS_X] + rowdistance * raydir[X][0];
	floor[Y] = data->player[POS_Y] + rowdistance * raydir[Y][0];
	fc_casting_2(data, y, floor, floorstep);
}

/**
 * @brief this one put the ceiling and floor texture thx to the coordinates
 * at the same time going from top to bottom of the image
 *
 * @param data
 * @param y
 * @param floor
 * @param floorstep
 */
void	fc_casting_2(t_data *data, int y, float *floor, float *floorstep)
{
	int	x;
	int	cell[2];
	int	texture_x;
	int	texture_y;

	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		cell[X] = (int)(floor[X]);
		cell[Y] = (int)(floor[Y]);
		texture_x = (int)(64 * (floor[X] - cell[X])) & (64 - 1);
		texture_y = (int)(64 * (floor[Y] - cell[Y])) & (64 - 1);
		floor[X] += floorstep[X];
		floor[Y] += floorstep[Y];
		data->img[RENDU].addr[y * data->img[RENDU].line_len / 4 + x]
			= data->img[FLOOR].addr[64 * texture_y + texture_x];
		data->img[RENDU].addr[(SCREEN_HEIGHT - y - 1)
			* data->img[RENDU].line_len / 4 + x]
			= data->img[CEIL].addr[64 * texture_y + texture_x];
	}
}
