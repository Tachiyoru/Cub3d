/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:06:57 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/05 16:19:22 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_map(t_data *data, int fd)
{
	t_lst	*maplst;
	t_lst	*tmp_map;

	maplst = store_map(fd);
	if (!maplst)
		return (1);
	tmp_map = maplst;
	while (tmp_map)
	{
		if (store_path(data, tmp_map))
			break ;
		tmp_map = tmp_map->next;
	}
	print_path(data);
	if (check_path(data))
		return (err_msg(MAP_INV, NULL, 2));
	printf("******************************************\n\n");
	if (store_map_data(data, tmp_map))
		return (free_lstmap(maplst), err_msg(MAP_INV, NULL, 1), 3);
	free_lstmap(maplst);
	return (0);
}
	// remplissage char **map
	//check wall apres ini_map

t_lst	*store_map(int fd)
{
	t_lst	*map_lst;
	t_lst	*tmp;
	char	*line;

	line = get_next_line(fd, 0);
	if (!line)
		return (err_msg(MALLOC, NULL, 1), NULL);
	tmp = ft_lstnew(line);
	map_lst = tmp;
	if (!tmp)
		return (err_msg(MALLOC, NULL, 2), NULL);
	while (line)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		ft_lstlast(tmp)->next = ft_lstnew(line);
	}
	return (map_lst);
}

int	store_path(t_data *data, t_lst *maplst)
{
	if (!maplst || !maplst->mapline)
		return (1);
	else if (ft_strncmp(maplst->mapline, "NO", 2))
	{
		if (data->image.path_n)
			return (2);
		data->image.path_n = ft_strndup(maplst->mapline, 0);
	}
	else if (ft_strncmp(maplst->mapline, "SO", 2))
	{
		if (data->image.path_s)
			return (2);
		data->image.path_s = ft_strndup(maplst->mapline, 0);
	}
	else if (ft_strncmp(maplst->mapline, "WE", 2))
	{
		if (data->image.path_w)
			return (2);
		data->image.path_w = ft_strndup(maplst->mapline, 0);
	}
	else
		return (store_path_2(data, maplst));
	return (0);
}

int	store_path_2(t_data *data, t_lst *maplst)
{
	if (ft_strncmp(maplst->mapline, "EA", 2))
	{
		if (data->image.path_e)
			return (2);
		data->image.path_e = ft_strndup(maplst->mapline, 0);
	}
	else if (maplst->mapline[0] == 'F')
	{
		if (data->image.path_f)
			return (2);
		data->image.path_f = ft_strndup(maplst->mapline, 0);
	}
	else if (maplst->mapline[0] == 'C')
	{
		if (data->image.path_c)
			return (2);
		data->image.path_c = ft_strndup(maplst->mapline, 0);
	}
	else if (maplst->mapline[0] != '\n')
		return (3);
	return (0);
}

int	check_path(t_data *data)
{
	if (data->image.path_n == NULL)
		return (1);
	else if (data->image.path_s == NULL)
		return (1);
	else if (data->image.path_w == NULL)
		return (1);
	else if (data->image.path_e == NULL)
		return (1);
	else if (data->image.path_f == NULL)
		return (1);
	else if (data->image.path_c == NULL)
		return (1);
	return (0);
}
