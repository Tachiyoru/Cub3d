/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txturs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:40:57 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/08 20:53:42 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->img[i].addr = (int *)mlx_get_data_addr(data->img[i].img,
			&data->img[i].bpp, &data->img[i].line_len, &data->img[i].endian);
			if (!data->img[i].addr)
				return (1);
		i++;
	}
	return (0);
}
