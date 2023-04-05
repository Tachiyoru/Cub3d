/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:26 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/05 18:49:20 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_data *data)
{
	// data->window_width = IMG_SIZE * data->map.line_len;
	// data->window_height = IMG_SIZE * data->map.line_count;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	// data->win_ptr = mlx_new_window(data->mlx_ptr, data->window_width,
	// 		data->window_height, "Shanuel");
	// if (data->win_ptr == NULL)
	// 	return (2);
	return (0);
}
