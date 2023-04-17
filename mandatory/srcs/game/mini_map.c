/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:50:24 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/12 14:13:16 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_map_minimap(t_data *data, int y, int x)
{
	if (y == (int)data->player[POS_Y] && x == (int)data->player[POS_X])
		print_box(data, y, x, 65025);
	else if (data->map.map[y][x] == '1')
		print_box(data, y, x, 0);
	else if (data->map.map[y][x] == '0')
		print_box(data, y, x, 16777215);
}

void	print_box(t_data *data, int y, int x, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			data->img[RENDU].addr[(y * 10) * data->img[RENDU].line_len / 4
				+ (x * 10)] = color;
			data->img[RENDU].addr[(y * 10 + j) * data->img[RENDU].line_len / 4
				+ (x * 10)] = color;
			data->img[RENDU].addr[(y * 10 + j) * data->img[RENDU].line_len / 4
				+ (x * 10 + i)] = color;
			data->img[RENDU].addr[(y * 10) * data->img[RENDU].line_len / 4
				+ (x * 10 + i)] = color;
			i++;
		}
		j++;
	}
}
