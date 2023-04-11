/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:37:07 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/11 15:57:50 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_background(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	while (j < SCREEN_HEIGTH / 2)
	{
		i = -1;
		while (++i < SCREEN_WIDTH)
			data->img[RENDU].addr[j * data->img[RENDU].line_len / 4 + i]
				= data->path.color_c;
		j++;
	}
	while (j < SCREEN_HEIGTH)
	{
		i = -1;
		while (++i < SCREEN_WIDTH)
			data->img[RENDU].addr[j * data->img[RENDU].line_len / 4 + i]
				= data->path.color_f;
		j++;
	}
}
static void	cam_pos(t_ray *ray, int screen_width, int x)
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
		ray->sidedist[X] = (ray->map[X] + 1.0 - ray->pos[X]) * ray->deltadist[X];
	if (ray->raydir[Y] < 0)
		ray->sidedist[Y] = (ray->pos[Y] - ray->map[Y]) * ray->deltadist[Y];
	else
		ray->sidedist[Y] = (ray->map[Y] + 1.0 - ray->pos[Y]) * ray->deltadist[Y];
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

void	init_walls(t_ray *ray, t_text *text)
{
	if (ray->side == 0 && ray->raydir[X] < 0)
		text->texdir = 0;
	if (ray->side == 0 && ray->raydir[X] > 0)
		text->texdir = 1;
	if (ray->side == 1 && ray->raydir[Y] < 0)
		text->texdir = 2;
	if (ray->side == 1 && ray->raydir[Y] > 0)
		text->texdir = 3;
	if (ray->side == 0)
		text->wallx = ray->pos[Y] + ray->paperwalldist * ray->raydir[Y];
	else
		text->wallx = ray->pos[X] + ray->paperwalldist * ray->raydir[X];
	text->wallx -= floor(text->wallx);
}

void	draw_wall(t_data *data, int x0, t_ray *ray, t_text *text)
{
	int	j;

	init_walls(ray, text);
	j = ray->drawstart;
	text->texx = (int)(text->wallx * (float)data->img[text->texdir].width);
	if (ray->side == 0 && ray->raydir[X] > 0)
		text->texx = data->img[text->texdir].width - text->texx - 1;
	if (ray->side == 1 && ray->raydir[Y] < 0)
		text->texx = data->img[text->texdir].width - text->texx - 1;
	text->step = 1.0 * data->img[text->texdir].height / ray->lineheight;
	text->texpos = (ray->drawstart - SCREEN_HEIGTH / 2 + \
		ray->lineheight / 2) * text->step;
	while (j <= ray->drawend)
	{
		text->texy = (int)text->texpos & (data->img[text->texdir].height - 1);
		text->texpos += text->step;
		if (j < SCREEN_HEIGTH && x0 < SCREEN_WIDTH)
			data->img[RENDU].addr[j * data->img[RENDU].line_len / 4 + x0]
				= data->img[text->texdir].addr[text->texy
				* data->img[text->texdir].line_len / 4 + text->texx];
		j++;
	}
}

void	raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cam_pos(&data->ray, SCREEN_WIDTH, x);
		ray_dist(&data->ray);
		dda_algo(&data->ray, &data->map);
		wall_lenght(&data->ray, SCREEN_HEIGTH);
		draw_wall(data, x, &data->ray, &data->text);
		x++;
	}
}

int	render(t_data *data)
{
	print_background(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[RENDU].img, 0, 0);
	return (0);
}
