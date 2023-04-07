/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:26:56 by sleon             #+#    #+#             */
/*   Updated: 2023/04/07 13:41:12 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_dir
{
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
}	t_dir;

int	init_rc(t_data *data)
{
	int		x;
	int		r;
	float	ra;
	double	dist[2];
	double	end_pos[2][2];

	init_player(data);
	x = 0;
	r = 0;
	ra = data->player.angle - ((1 * data->pi / 180) * 30);
	while (r < 1000)
	{
	}
}

void	init_player(t_data *data)
{
	data->player.pos_x += 0.5f;
	data->player.pos_y += 0.5f;
	data->player.pixel_x = data->player.pos_x * 64;
	data->player.pixel_y = data->player.pos_y * 64;
	data->delta[0] = cos(data->player.angle) * 5;
	data->delta[1] = sin(data->player.angle) * 5;
}
