/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:20:40 by sleon             #+#    #+#             */
/*   Updated: 2023/04/04 16:58:06 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_data *data, char *file)
{
	int		fd;

	if (!check_cub(file))
		return ((1)); // map_checker_error
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror(NULL), 2);
	if (!init_map(data, fd))
		return (close(fd), 3); // free_map(data)
	close(fd);
	return (0);
}
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
		return (0);
	return (1);
}
