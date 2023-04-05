/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:20:40 by sleon             #+#    #+#             */
/*   Updated: 2023/04/05 16:25:30 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_data *data, char *file)
{
	int		fd;

	if (check_cub(file))
		return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (err_msg(file, OPEN, 2));
	if (init_map(data, fd))
		return (close(fd), 3);
	close(fd);
	print_tab(data->map.map);
	if (check_space(data))
		return (err_msg(MAP_INV, NULL, 4));
	return (0);
}
	// check_open(data->image); // check que c bien des xpm et si on peut les ouvrir
	// check_player(data->map);
	// check_wall(data->map)

/**
 * @brief
 *
 * @param file
 * @return int
 */
int	check_cub(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (file[size - 4] != '.' || file[size - 3] != 'c'
		|| file[size - 2] != 'u' || file[size - 1] != 'b')
		return (err_msg(file, NOT_CUM, 1));
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
