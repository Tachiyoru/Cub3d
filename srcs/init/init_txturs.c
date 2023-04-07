/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txturs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:40:57 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/07 18:06:31 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_data *data)
{
	data->txt[0].addr = (int *)mlx_get_data_addr(data->txt[0].img, &data->txt[0].bpp, &data->txt[0].line_len, &data->txt[0].endian);
	data->txt[1].addr = (int *)mlx_get_data_addr(data->txt[1].img, &data->txt[1].bpp, &data->txt[1].line_len, &data->txt[1].endian);
	data->txt[2].addr = (int *)mlx_get_data_addr(data->txt[2].img, &data->txt[2].bpp, &data->txt[2].line_len, &data->txt[2].endian);
	data->txt[3].addr = (int *)mlx_get_data_addr(data->txt[3].img, &data->txt[3].bpp, &data->txt[3].line_len, &data->txt[3].endian);
}
