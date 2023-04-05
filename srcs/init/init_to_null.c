/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:54:44 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/05 18:41:03 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_to_null_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->win_lentgh = 0;
	data->win_width = 0;
	data->player.start_x = 0;
	data->player.start_y = 0;
	data->map.map = NULL;
	data->map.size_x = 0;
	data->map.size_y = 0;
	init_to_null_img(data);
}

void	init_to_null_img(t_data *data)
{
	data->image.path_n = NULL;
	data->image.path_s = NULL;
	data->image.path_w = NULL;
	data->image.path_e = NULL;
	data->image.path_f = NULL;
	data->image.path_c = NULL;
}
