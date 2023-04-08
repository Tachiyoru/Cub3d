/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:54:44 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/08 21:18:49 by sleon            ###   ########.fr       */
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
		data->img[i].img= NULL;
		i++;
	}
}

void	init_to_null_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->player[POS_X] = 0;
	data->player[POS_Y] = 0;
	data->map.map = NULL;
	data->map.size_x = 0;
	data->map.size_y = 0;
	data->image.color_c = 0;
	data->image.color_f = 0;
	init_to_null_img(data);
	init_txturs_to_null(data);
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

// void	init_rc_to_null(t_rc *rc)
// {
// 	rc->hit = 0;
// 	rc->camera_x = 0;
// 	rc->txt_dir = 0;
// 	rc->d_dist_x = 0;
// 	rc->perp_wall_dist = 0;
// 	rc->line_height = 0;
// 	rc->d_dist_y = 0;
// 	rc->side = 0;
// 	rc->plan_x = 0;
// 	rc->plan_y = 0;
// 	rc->raydir_x = 0;
// 	rc->raydir_y = 0;
// 	rc->side_dist_x = 0;
// 	rc->side_dist_y = 0;
// 	rc->v_dir_x = 0;
// 	rc->v_dir_y = 0;
// }

