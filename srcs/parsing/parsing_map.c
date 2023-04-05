/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:20:18 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/05 16:36:50 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_space(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = create_copy_map(data->map.map);
	if (!map)
		return (1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == ' ')
				if (recursive(map, y, x))
				{
					free_tab(map, 0);
					return (1);
				}
			x++;
		}
		y++;
	}
	free_tab(map, 0);
	return (0);
}

int	recursive(char **map, int y, int x)
{
	if (map[y][x] == '0')
		return (1);
	map[y][x] = '1';
	if (x - 1 > 0 && map[y][x - 1] != '1')
		if (recursive(map, y, x - 1))
			return (1);
	if (y - 1 > 0 && map[y - 1][x] != '1')
		if (recursive(map, y - 1, x))
			return (1);
	if (x + 1 < ft_strlen(map[y]) && map[y][x + 1] != '1')
		if (recursive(map, y, x + 1))
			return (1);
	if (map[y + 1] && map[y + 1][x] != '1')
		if (recursive(map, y + 1, x))
			return (1);
	return (0);
}

int	verif_char(t_lst *check)
{
	int	i;

	while (check)
	{
		i = 0;
		while (check->mapline[i])
		{
			if (check->mapline[i] == ' ' || check->mapline[i] == '0'
				|| check->mapline[i] == '1' || check->mapline[i] == '\n')
				i++;
			else if (check->mapline[i] == 'N' || check->mapline[i] == 'S'
				|| check->mapline[i] == 'W' || check->mapline[i] == 'E')
				i++;
			else
				return (1);
		}
		check = check->next;
	}
	return (0);
}
