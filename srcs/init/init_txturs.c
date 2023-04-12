/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txturs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:40:57 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/12 14:22:54 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_rendu(t_data *data)
{
	data->img[RENDU].img = mlx_new_image(data->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	if (!data->img[RENDU].img)
		return (err_msg(NULL, INIT_IMG, 1));
	data->img[RENDU].addr = (int *)mlx_get_data_addr(data->img[RENDU].img,
			&data->img[RENDU].bpp, &data->img[RENDU].line_len,
			&data->img[RENDU].endian);
	if (!data->img[RENDU].addr)
		return (err_msg(NULL, DATA_ADDR, 2));
	return (0);
}

int	init_images(t_data *data)
{
	data->img[WALL_NORTH].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.path_n, &data->img[WALL_NORTH].width,
			&data->img[WALL_NORTH].height);
	if (!data->img[WALL_NORTH].img)
		return (err_msg(data->path.path_n, XPM, 1));
	data->img[WALL_SOUTH].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.path_s, &data->img[WALL_SOUTH].width,
			&data->img[WALL_SOUTH].height);
	if (!data->img[WALL_SOUTH].img)
		return (err_msg(data->path.path_s, XPM, 2));
	data->img[WALL_WEST].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.path_w, &data->img[WALL_WEST].width,
			&data->img[WALL_WEST].height);
	if (!data->img[WALL_WEST].img)
		return (err_msg(data->path.path_w, XPM, 3));
	data->img[WALL_EAST].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.path_e, &data->img[WALL_EAST].width,
			&data->img[WALL_EAST].height);
	if (!data->img[WALL_EAST].img)
		return (err_msg(data->path.path_e, XPM, 4));
	return (0);
}

int	init_textures(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		data->img[i].addr = (int *)mlx_get_data_addr(data->img[i].img,
				&data->img[i].bpp, &data->img[i].line_len,
				&data->img[i].endian);
		if (!data->img[i].addr)
			return (1);
	}
	return (0);
}
