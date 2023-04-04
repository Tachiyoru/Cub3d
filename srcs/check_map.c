/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:20:40 by sleon             #+#    #+#             */
/*   Updated: 2023/04/04 17:14:21 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief
 *
 * @param data
 * @param file
 * @return int
 */
int	check_map(t_data *data, char *file)
{
	int		fd;
	t_lst	**map_lst;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(1, "Failed to open\n", 16), 0);
	map_lst = malloc(sizeof(t_lst *));
	if (!map_lst)
		return (0);
	if (!init_map(data, fd, map_lst))
		return (free_map(data), 0);
	return (1);
}

int	check_cub(char *file)
{
	int	fd;
	int	size;

	size = ft_strlen(file);
	if (file[size - 4] != '.' || file[size - 3] != 'c'
		|| file[size - 2] != 'u' || file[size - 1] != 'b')
		return (0);
	return (1);
}

int	init_map(t_data *data, int fd, t_lst **maplst)
{
	size_t	size;

	data->map.collectible = 0;
	data->map.exit = 0;
	data->map.player = 0;
	data->map.ennemy = 0;
	size = 0;
	data->player.move_count = 0;
	data->player.collected = 0;
	data->map.lines = count_lines(fd, 1, maplst, size);
	if (data->map.lines == -1)
		return (lines_error(3));
	if (data->map.lines < 3)
		return (lines_error(1));
	if (!check_wall(maplst, size))
		return (free_lst(maplst), wall_checker_error(1));
	data->map.size_y = data->map.lines;
	data->map.size_x = ft_strlen2((*maplst)->mapline);
	data->map.map = ft_calloc(data->map.lines + 1, sizeof(char *));
	if (!data->map.map)
		return (free_lst(maplst), 0);
	return (1);
}
