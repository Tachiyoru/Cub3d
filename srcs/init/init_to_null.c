/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:54:44 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/15 17:01:25 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_txturs_to_null(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->img[i].addr = NULL;
		data->img[i].bpp = 0;
		data->img[i].endian = 0;
		data->img[i].img = NULL;
		i++;
	}
}

void	init_to_null_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->q = 0;
	data->ray.door = 0;
	data->mouse_pos = 10000;
	data->player_speed = 0.05;
	data->player[POS_X] = 0;
	data->player[POS_Y] = 0;
	data->map.map = NULL;
	data->map.size_x = 0;
	data->map.size_y = 0;
	data->path.color_c = 0;
	data->path.color_f = 0;
	init_to_null_img(data);
	init_txturs_to_null(data);
}

void	init_to_null_img(t_data *data)
{
	data->path.path_n = NULL;
	data->path.path_s = NULL;
	data->path.path_w = NULL;
	data->path.path_e = NULL;
	data->path.path_f = NULL;
	data->path.path_c = NULL;
}
