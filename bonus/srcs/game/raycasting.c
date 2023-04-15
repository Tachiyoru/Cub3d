/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:33:06 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/15 12:47:31 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SCREEN_HEIGHT)
		floor_ceiling_casting(data, y);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cam_pos(&data->ray, SCREEN_WIDTH, x);
		ray_dist(&data->ray);
		dda_algo(&data->ray, &data->map);
		wall_lenght(&data->ray, SCREEN_HEIGHT);
		draw_wall(data, x, &data->ray, &data->text);
		x++;
	}
}

void	cam_pos(t_ray *ray, int screen_width, int x)
{
	ray->cam_x = 2.0 * x / (double)screen_width - 1;
	ray->raydir[X] = ray->dir[X] + ray->plan[X] * ray->cam_x;
	ray->raydir[Y] = ray->dir[Y] + ray->plan[Y] * ray->cam_x;
	ray->map[X] = (int)ray->pos[X];
	ray->map[Y] = (int)ray->pos[Y];
	ray->deltadist[X] = fabs(1 / ray->raydir[X]);
	ray->deltadist[Y] = fabs(1 / ray->raydir[Y]);
}

void	ray_dist(t_ray *ray)
{
	if (ray->raydir[X] < 0)
		ray->sidedist[X] = (ray->pos[X] - ray->map[X]) * ray->deltadist[X];
	else
		ray->sidedist[X] = (ray->map[X] + 1.0 - ray->pos[X])
			* ray->deltadist[X];
	if (ray->raydir[Y] < 0)
		ray->sidedist[Y] = (ray->pos[Y] - ray->map[Y]) * ray->deltadist[Y];
	else
		ray->sidedist[Y] = (ray->map[Y] + 1.0 - ray->pos[Y])
			* ray->deltadist[Y];
	if (ray->raydir[X] < 0)
		ray->step[X] = -1;
	else
		ray->step[X] = 1;
	if (ray->raydir[Y] < 0)
		ray->step[Y] = -1;
	else
		ray->step[Y] = 1;
}

void	dda_algo(t_ray *ray, t_map *map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedist[X] < ray->sidedist[Y])
		{
			ray->sidedist[X] += ray->deltadist[X];
			ray->map[X] += ray->step[X];
			ray->side = 0 ;
		}
		else
		{
			ray->sidedist[Y] += ray->deltadist[Y];
			ray->map[Y] += ray->step[Y];
			ray->side = 1 ;
		}
		if (map->map[ray->map[Y]][ray->map[X]] == '1')
			ray->hit = 1;
		else if (map->map[ray->map[Y]][ray->map[X]] == 'X')
			ray->hit = 1;
	}
}

void	wall_lenght(t_ray *ray, int screen_height)
{
	if (ray->side == 0)
		ray->paperwalldist = (ray->sidedist[X] - ray->deltadist[X]);
	else
		ray->paperwalldist = (ray->sidedist[Y] - ray->deltadist[Y]);
	if (ray->paperwalldist == 0)
		ray->paperwalldist = 0.01;
	ray->lineheight = (double)(screen_height / ray->paperwalldist);
	ray->drawstart = (screen_height / 2) - (ray->lineheight / 2);
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = (screen_height / 2) + (ray->lineheight / 2);
	if (ray->drawend >= screen_height)
		ray->drawend = screen_height;
}
