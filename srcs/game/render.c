/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:37:07 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/17 18:07:58 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	print_background(data);
	raycasting(data);
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			convert_map_minimap(data, y, x);
			x++;
		}
		y++;
	}
	if (surprise_mother_fucker(data))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img[RENDU].img, 0, 0);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img[RENDU].img, 0, 0);
	return (0);
}

int	surprise_mother_fucker(t_data *data)
{
	if ((int)data->player[POS_X] == 4 && (int)data->player[POS_Y] == 10
		&& data->q <= 4)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img[SURPRISE].img, 400, 200);
		data->q++;
		return (0);
	}
	return (1);
}

void	print_background(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	while (j < SCREEN_HEIGHT / 2)
	{
		i = -1;
		while (++i < SCREEN_WIDTH)
			data->img[RENDU].addr[j * data->img[RENDU].line_len / 4 + i]
				= data->path.color_c;
		j++;
	}
	while (j < SCREEN_HEIGHT)
	{
		i = -1;
		while (++i < SCREEN_WIDTH)
			data->img[RENDU].addr[j * data->img[RENDU].line_len / 4 + i]
				= data->path.color_f;
		j++;
	}
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

void	draw_wall(t_data *data, int x, t_ray *ray, t_text *text)
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
	text->texpos = (ray->drawstart - SCREEN_HEIGHT / 2 + \
		ray->lineheight / 2) * text->step;
	while (j <= ray->drawend)
	{
		text->texy = (int)text->texpos & (data->img[text->texdir].height - 1);
		text->texpos += text->step;
		if (j < SCREEN_HEIGHT && x < SCREEN_WIDTH)
			data->img[RENDU].addr[j * data->img[RENDU].line_len / 4 + x]
				= data->img[text->texdir].addr[text->texy
				* data->img[text->texdir].line_len / 4 + text->texx];
		j++;
	}
}
