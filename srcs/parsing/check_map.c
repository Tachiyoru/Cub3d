/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:20:40 by sleon             #+#    #+#             */
/*   Updated: 2023/04/11 17:01:46 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_data *data, char *file)
{
	int		fd;

	if (check_ext(file, ".cub"))
		return (err_msg(file, NOT_CUM, 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (err_msg(file, OPEN, 2));
	if (init_map(data, fd))
		return (close(fd), 3);
	close(fd);
	if (init_rgb(data))
		return (free_tab(data->map.map, 0), free_path(data->path),
			err_msg(RGB, NULL, 4));
	if (check_open(data->path))
		return (free_tab(data->map.map, 0), free_path(data->path), 5);
	if (check_wall(data->map.map))
		return (free_tab(data->map.map, 0), free_path(data->path),
			err_msg(WALLS, NULL, 6));
	return (0);
}

// Return 0 si la map est entouree de 1 sinon 0
int	check_wall(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
				if (check_around(map, y, x))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

char	**create_copy_map(char **map)
{
	char	**tab;
	int		i;

	i = 0;
	while (map[i])
		i++;
	tab = ft_calloc(i + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	tab[i] = NULL;
	i = 0;
	while (map[i])
	{
		tab[i] = ft_strndup(map[i], 0);
		if (!tab[i])
			return (NULL);
		i++;
	}
	return (tab);
}
