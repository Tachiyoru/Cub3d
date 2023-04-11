/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:34:40 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/11 14:33:00 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx-ax) + (by - ay) * (by - ay)));
}

void	ray_pos(t_data *data)
{
	double	angle_tan;
	double	dist_tot;
	double	n_tan;
	double	ry;
	double	rx;
	double	yo;
	double	xo;
	int		n_case;
	int		map_x;
	int		map_pos;
	int		map_y;
	int		n_ray;

	n_ray = 0;
	data->rc.ray_angle = data->player.angle - 30 * DR;
	if (data->rc.ray_angle < 0)
		data->rc.ray_angle += 2 * PI;
	else if (data->rc.ray_angle > 2 * PI)
		data->rc.ray_angle -=2 * PI;
	while (n_ray < 60)
	{
		// Check horizontal lines 
		n_case = 0;
		double	dis_horiz = 1000000;
		double	hx = data->player.pos_x;
		double	hy = data->player.pos_y;
		angle_tan = -1 / tan(data->rc.ray_angle);
		// looking DOWN
		if (data->rc.ray_angle > PI)
		{
			ry = (((int)data->player.pos_y >> 6) << 6) - 0.0001;
			rx = (data->player.pos_y - ry) * angle_tan + data->player.pos_x;
			yo = -64;
			xo = -yo * angle_tan;
		}
		// looking UP
		else if (data->rc.ray_angle < PI)
		{
			ry = (((int)data->player.pos_y >> 6) << 6) + 64;
			rx = (data->player.pos_y - ry) * angle_tan + data->player.pos_x;
			yo = 64;
			xo = -yo * angle_tan;
		}
		// looking straight LEFT or RIGHT
		else if (data->rc.ray_angle == 0 || data->rc.ray_angle == PI)
		{
			hx = rx;
			hy = ry;
			dis_horiz = dist(data->player.pos_x, data->player.pos_y, hx, hy);
			n_case = data->map.size_x;
		}
		while (n_case < data->map.size_x)
		{
			map_x = (int)rx >> 6;
			map_y = (int)ry >> 6;
			map_pos = map_y * data->map.size_x + map_x;
			if (map_pos > 0 && map_pos < data->map.size_x && data->map.map[map_y][map_x] == '1') // hit a wall
				n_case = data->map.size_x;
			else //next line
			{
				rx += xo;
				ry += yo;
				n_case++;
			}
		}

		double	dis_ver = 1000000;
		double	vx = data->player.pos_x;
		double	vy = data->player.pos_y;
		// Check vertical lines 
		n_case = 0;
		n_tan = -tan(data->rc.ray_angle);
		// looking LEFT
		if (data->rc.ray_angle > PI / 2 && data->rc.ray_angle < (3 * PI) / 2)
		{
			rx = (((int)data->player.pos_x >> 6) << 6) - 0.0001;
			ry = (data->player.pos_x - rx) * n_tan + data->player.pos_y;
			xo = -64;
			yo = -yo * n_tan;
		}
		// looking RIGHT
		else if (data->rc.ray_angle < PI / 2 || data->rc.ray_angle > (3 * PI) /2)
		{
			rx = (((int)data->player.pos_x >> 6) << 6) + 64;
			ry = (data->player.pos_x - rx) * n_tan + data->player.pos_y;
			xo = 64;
			yo = -yo * n_tan;
		}
		// looking straight UP or DOWN
		else if (data->rc.ray_angle == 0 || data->rc.ray_angle == PI)
		{
			n_case = data->map.size_x;
			rx = vx;
			ry = vy;
			dis_ver = dist(data->player.pos_x, data->player.pos_y, vx, vy);
		}
		while (n_case < data->map.size_x)
		{
			map_x = (int)rx >> 6;
			map_y = (int)ry >> 6;
			map_pos = map_y * data->map.size_x + map_x;
			if (map_pos > 0 &&  map_pos < data->map.size_x * data->map.size_y && data->map.map[map_y][map_x] == '1') // hit a wall
				n_case = data->map.size_x;
			else //next line
			{
				rx += xo;
				ry += yo;
				n_case++;
			}
		}
		if (dis_ver < dis_horiz)
		{
			printf("dis_ver : %f\n", dis_ver);
			rx = vx;
			ry = vy;
			dist_tot = dis_ver;
		}
		else
		{
			printf("dis_horiz : %f\n", dis_horiz);
			rx = hx;
			ry = hy;
			dist_tot = dis_horiz;
		}
		n_ray++;
		data->rc.ray_angle += DR;
		printf("%f\n", dist_tot);
	}
}
