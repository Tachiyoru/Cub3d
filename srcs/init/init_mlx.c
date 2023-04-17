/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:26 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/15 19:27:46 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_data *data)
{
	data->player[POS_X] += 0.5;
	data->player[POS_Y] += 0.5;
	data->player[POS_PXL_X] = data->player[POS_X] * 64;
	data->player[POS_PXL_Y] = data->player[POS_Y] * 64;
}

int	check_screen_size(t_data *data)
{
	int	width;
	int	height;

	mlx_get_screen_size(data->mlx_ptr, &width, &height);
	if (SCREEN_WIDTH > width || SCREEN_HEIGHT > height)
		return (err_msg(SCREEN, NULL, 1));
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	if (check_screen_size(data))
		return (2);
	data->win_ptr = mlx_new_window(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			"Mansha");
	if (data->win_ptr == NULL)
		return (2);
	if (init_images(data))
		return (3);
	if (init_textures(data))
		return (4);
	if (init_rendu(data))
		return (5);
	init_player(data);
	data->ray.pos[X] = (double)data->player[POS_X];
	data->ray.pos[Y] = (double)data->player[POS_Y];
	return (0);
}

void	loop_hook(t_data data)
{
	// mlx_mouse_hide(data.mlx_ptr, data.win_ptr); //leak
	mlx_hook(data.win_ptr, MotionNotify, PointerMotionMask, &mouse_move, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
		&handle_btnrealease, &data);
	mlx_loop(data.mlx_ptr);
}
