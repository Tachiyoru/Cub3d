/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:37:07 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/11 17:17:01 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_data *data)
{
	print_background(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[RENDU].img, 0, 0);
	return (0);
}

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
