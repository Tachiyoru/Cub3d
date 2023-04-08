/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:26 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/08 21:19:36 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGTH,
			"Shanuel");
	if (data->win_ptr == NULL)
		return (2);
	if (init_images(data))
		return (3);
	if (init_textures(data))
		return (4);
	return (0);
}

int	init_images(t_data *data)
{
	int size = IMG_SIZE;

	data->img[WALL_NORTH].img = mlx_xpm_file_to_image(data->mlx_ptr, data->image.path_n,\
		&size, &size);
	if (!data->img[WALL_NORTH].img)
		return (err_msg(data->image.path_n, XPM, 1));
	data->img[WALL_NORTH].addr = (int *)mlx_get_data_addr(data->img[WALL_NORTH].img, &data->img[WALL_NORTH].bpp,
			&data->img[WALL_NORTH].line_len, &data->img[WALL_NORTH].endian);
	data->img[WALL_SOUTH].img = mlx_xpm_file_to_image(data->mlx_ptr, data->image.path_s,\
		&size, &size);
	if (!data->img[WALL_SOUTH].img)
		return (err_msg(data->image.path_s, XPM, 2));
	data->img[WALL_SOUTH].addr = (int *)mlx_get_data_addr(data->img[WALL_SOUTH].img, &data->img[WALL_SOUTH].bpp,
			&data->img[WALL_SOUTH].line_len, &data->img[WALL_SOUTH].endian);
	data->img[WALL_WEST].img = mlx_xpm_file_to_image(data->mlx_ptr, data->image.path_w,\
		&size, &size);
	if (!data->img[WALL_WEST].img)
		return (err_msg(data->image.path_w, XPM, 3));
	data->img[WALL_WEST].addr = (int *)mlx_get_data_addr(data->img[WALL_WEST].img, &data->img[WALL_WEST].bpp,
			&data->img[WALL_WEST].line_len, &data->img[WALL_WEST].endian);
	data->img[WALL_EAST].img = mlx_xpm_file_to_image(data->mlx_ptr, data->image.path_e,\
		&size, &size);
	if (!data->img[WALL_EAST].img)
		return (err_msg(data->image.path_e, XPM, 4));
	data->img[WALL_EAST].addr = (int *)mlx_get_data_addr(data->img[WALL_EAST].img, &data->img[WALL_EAST].bpp,
			&data->img[WALL_EAST].line_len, &data->img[WALL_EAST].endian);
	return (0);
}
	// data->img[IMAGE].img = mlx_xpm_file_to_image(data->mlx_ptr, data->image.path_n,\
	// 	&size, &size);
	// if (!data->img[IMAGE].img)
	// 	return (err_msg(data->image.path_n, XPM, 1));
	// data->img[IMAGE].addr = (int *)mlx_get_data_addr(data->img[IMAGE], &data->img[IMAGE].bpp,
	// 		&data->img[IMAGE].line_len, &data->img[IMAGE].endian);

void	loop_hook(t_data data)
{
	// mlx_loop_hook(data.mlx_ptr, &render, &data); // bonne vanne sa mere
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
		&handle_btnrealease, &data);
	mlx_loop(data.mlx_ptr);
}
