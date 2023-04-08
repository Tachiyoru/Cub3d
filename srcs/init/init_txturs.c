/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txturs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:40:57 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/08 18:51:18 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->txt[i].addr = (int *)mlx_get_data_addr(data->txt[i].img,
			&data->txt[i].bpp, &data->txt[i].line_len, &data->txt[i].endian);
			if (!data->txt[i].addr)
				return (1);
		i++;
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH_SCREEN, HEIGHT_SCREEN);
	data->img.addr = (int *)mlx_get_data_addr(data->image.mlx_img , &data->img.bpp, &data->img.line_len, &data->img.endian);
	return (0);
}
