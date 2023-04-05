/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:20:40 by sleon             #+#    #+#             */
/*   Updated: 2023/04/05 13:42:45 by sleon            ###   ########.fr       */
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
	printf("\nsixe_x = %d", data->map.size_x);
	printf(" / sixe_y = %d\n", data->map.size_y);
	printf("ready for next\n");
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
