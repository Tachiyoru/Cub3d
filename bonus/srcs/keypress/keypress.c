/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:15:51 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/15 14:03:08 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		free_all(data);
		exit (7);
	}
	if (keysym == K_LEFT)
		move_cam(data, -0.05);
	if (keysym == K_RIGHT)
		move_cam(data, 0.05);
	if (keysym == XK_Shift_L)
	{
		if (data->player_speed == 0.05)
			data->player_speed *= 2;
		else
			data->player_speed = 0.05;
	}
	if (keysym == K_W)
		move_player(data, 'W');
	if (keysym == K_S)
		move_player(data, 'S');
	if (keysym == K_A)
		move_player(data, 'A');
	if (keysym == K_D)
		move_player(data, 'D');
	return (keysym);
}

int	handle_btnrealease(t_data *data)
{
	free_all(data);
	exit (8);
	return (0);
}
