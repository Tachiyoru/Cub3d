/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:34:40 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/08 20:28:19 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	float	angle_tan;
	float	ry;
	float	rx;
	float	yo;
	float	xo;
	int		n_case;
	int		map_x;
	int		map_y;
	int		n_ray;

	n_ray = 0;
	n_case = 0;
	while (n_ray < 1)
	{
		// Check horizontal lines 
		angle_tan = -1 / tan(data->rc.ray_angle);
		// looking DOWN
		if (data->rc.ray_angle > PI)
		{
			ry = (((int)data->player.pos_y >> 6) << 6) - 0.0001;
			rx = (data->player.pos_x - ry) * aTan() + data->player.pos_x;
			yo = -64;
			xo = -yo * aTan();
		}
		// looking UP
		else if (data->rc.ray_angle < PI)
		{
			ry = (((int)data->player.pos_y >> 6) << 6) + 64;
			rx = (data->player.pos_x - ry) * aTan() + data->player.pos_x;
			yo = 64;
			xo = -yo * aTan();
		}
		// looking straight LEFT or RIGHT
		else if (data->rc.ray_angle == 0 || data->rc.ray_angle == PI)
		{
			while (n_case < data->map.size_x)
			{
				map_x = (int)rx >> 6;
				
			}
		}
		n_ray++;
	}
	
}
