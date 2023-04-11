/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:26 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/11 17:11:16 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player(t_data *data)
{
	data->player[POS_X] += 0.5;
	data->player[POS_Y] += 0.5;
	data->player[POS_PXL_X] = data->player[POS_X] * 64;
	data->player[POS_PXL_Y] = data->player[POS_Y] * 64;
	return (0);
}

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
	if (init_rendu(data))
		return (0);
	if (init_player(data))
		return (0);
	data->ray.pos[X] = (double)data->player[POS_X];
	data->ray.pos[Y] = (double)data->player[POS_Y];
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
