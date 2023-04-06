/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:20:40 by sleon             #+#    #+#             */
/*   Updated: 2023/04/06 17:05:47 by msharifi         ###   ########.fr       */
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
		return (free_tab(data->map.map, 0), free_path(data->image),
			err_msg(RGB, NULL, 5));
	if (check_wall(data->map.map))
		return (free_tab(data->map.map, 0), free_path(data->image),
			err_msg(WALLS, NULL, 5));
	return (0);
}
	//check_open(data->image)

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
