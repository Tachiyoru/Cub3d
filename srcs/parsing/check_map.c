/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:20:40 by sleon             #+#    #+#             */
/*   Updated: 2023/04/05 16:20:39 by sleon            ###   ########.fr       */
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
	print_tab(data->map.map);
	if (check_open(data->image))
		return (free_img(data->image), 1);
	return (0);
}
	// check_player(data->map); //un seul N S W E
	// check_wall(data->map); //Verifier que toute la map est entoure de 1
	// check_inside(data->map); // verifier qu'il n'y a pas d'espace a l'interieur de la map

/**
 * @brief
 *
 * @param file
 * @return int
 */
int	check_ext(char *file, char *str)
{
	int	size;

	size = ft_strlen(file);
	if (file[size - 4] != str[0] || file[size - 3] != str[1]
		|| file[size - 2] != str[2] || file[size - 1] != str[3])
		return (1);
	return (0);
}

int	check_open(t_image img)
{
	int		fd[4];

	if (check_ext(img.path_n, ".xpm"))
		return (err_msg("North", NOT_XPM, 1));
	else if (check_ext(img.path_s, ".xpm"))
		return (err_msg("South", NOT_XPM, 1));
	else if (check_ext(img.path_w, ".xpm"))
		return (err_msg("West", NOT_XPM, 1));
	else if (check_ext(img.path_e, ".xpm"))
		return (err_msg("East", NOT_XPM, 1));
	fd[0] = open(img.path_n, O_RDONLY);
	fd[1] = open(img.path_s, O_RDONLY);
	fd[2] = open(img.path_w, O_RDONLY);
	fd[3] = open(img.path_e, O_RDONLY);
	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1 || fd[3] == -1)
		return (close_txtures(fd), err_msg(OPEN_TXTUR, NULL, 1));
	close_txtures(fd);
	return (0);
}
	// if (check_textures_size(img))
	// 	return (1);

void	close_txtures(int *fd)
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	if (fd[2] != -1)
		close(fd[2]);
	if (fd[3] != -1)
		close(fd[3]);
}
