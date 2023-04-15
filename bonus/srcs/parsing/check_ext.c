/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:58:05 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/15 16:54:51 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_ext(char *file, char *str)
{
	int	size;

	size = ft_strlen(file);
	if (file[size - 4] != str[0] || file[size - 3] != str[1]
		|| file[size - 2] != str[2] || file[size - 1] != str[3])
		return (1);
	return (0);
}

int	check_open(t_path img)
{
	int		fd[6];

	if (check_ext(img.path_n, ".xpm"))
		return (err_msg("North", NOT_XPM, 1));
	else if (check_ext(img.path_s, ".xpm"))
		return (err_msg("South", NOT_XPM, 1));
	else if (check_ext(img.path_w, ".xpm"))
		return (err_msg("West", NOT_XPM, 1));
	else if (check_ext(img.path_e, ".xpm"))
		return (err_msg("East", NOT_XPM, 1));
	else if (check_ext(img.path_f, ".xpm"))
		return (err_msg("Floor", NOT_XPM, 1));
	else if (check_ext(img.path_c, ".xpm"))
		return (err_msg("Ceiling", NOT_XPM, 1));
	fd[0] = open(img.path_n, O_RDONLY);
	fd[1] = open(img.path_s, O_RDONLY);
	fd[2] = open(img.path_w, O_RDONLY);
	fd[3] = open(img.path_e, O_RDONLY);
	fd[4] = open(img.path_f, O_RDONLY);
	fd[5] = open(img.path_c, O_RDONLY);
	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1 || fd[3] == -1
		|| fd[4] == -1 || fd[5] == -1)
		return (close_txtures(fd), err_msg(OPEN_TXTUR, NULL, 1));
	close_txtures(fd);
	if (check_textures_size(img))
		return (2);
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
	if (fd[4] != -1)
		close(fd[4]);
	if (fd[5] != -1)
		close(fd[5]);
}
