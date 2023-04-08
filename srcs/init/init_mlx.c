/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:26 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/08 16:50:35 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH_SCREEN, HEIGHT_SCREEN,
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
	data->image.width = WIDTH_IMG;
	data->image.height = HEIGHT_IMG;
	data->txt[0].img = mlx_xpm_file_to_image(data->mlx_ptr, data->image.path_n,\
		&data->image.width, &data->image.height);
	if (!data->txt[0].img)
		return (err_msg(data->image.path_n, XPM, 1));
	data->txt[1].img = mlx_xpm_file_to_image(data->mlx_ptr, data->image.path_s,\
		&data->image.width, &data->image.height);
	if (!data->txt[1].img)
		return (err_msg(data->image.path_s, XPM, 2));
	data->txt[2].img = mlx_xpm_file_to_image(data->mlx_ptr, data->image.path_w,\
		&data->image.width, &data->image.height);
	if (!data->txt[2].img)
		return (err_msg(data->image.path_w, XPM, 3));
	data->txt[3].img = mlx_xpm_file_to_image(data->mlx_ptr, data->image.path_e,\
		&data->image.width, &data->image.height);
	if (!data->txt[3].img)
		return (err_msg(data->image.path_e, XPM, 4));
	return (0);
}

void	loop_hook(t_data data)
{
	mlx_loop_hook(data.mlx_ptr, &render, &data); // bonne vanne sa mere
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
		&handle_btnrealease, &data);
	mlx_loop(data.mlx_ptr);
}
