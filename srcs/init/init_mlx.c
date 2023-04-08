/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:26 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/08 19:18:59 by msharifi         ###   ########.fr       */
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
	return (0);
}

// void	loop_hook(t_data data)
// {
// 	mlx_loop_hook(data.mlx_ptr, &render, &data); // bonne vanne sa mere
// 	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
// 	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
// 		&handle_btnrealease, &data);
// 	mlx_loop(data.mlx_ptr);
// }
