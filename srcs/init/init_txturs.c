/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txturs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:40:57 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/11 12:25:42 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_images(t_data *data)
{
	int	size;

	size = IMG_SIZE;
	data->img[WALL_NORTH].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.path_n, &size, &size);
	if (!data->img[WALL_NORTH].img)
		return (err_msg(data->path.path_n, XPM, 1));
	data->img[WALL_SOUTH].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.path_s, &size, &size);
	if (!data->img[WALL_SOUTH].img)
		return (err_msg(data->path.path_s, XPM, 2));
	data->img[WALL_WEST].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.path_w, &size, &size);
	if (!data->img[WALL_WEST].img)
		return (err_msg(data->path.path_w, XPM, 3));
	data->img[WALL_EAST].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path.path_e, &size, &size);
	if (!data->img[WALL_EAST].img)
		return (err_msg(data->path.path_e, XPM, 4));
	return (0);
}

// data->img[IMAGE].img = mlx_xpm_file_to_image(data->mlx_ptr,
	//data->image.path_n, &size, &size);
// if (!data->img[IMAGE].img)
// 	return (err_msg(data->image.path_n, XPM, 1));
// data->img[IMAGE].addr = (int *)mlx_get_data_addr(data->img[IMAGE],
	//&data->img[IMAGE].bpp, &data->img[IMAGE].line_len,
	//&data->img[IMAGE].endian);

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
