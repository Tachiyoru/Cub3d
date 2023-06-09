/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:06:57 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/15 17:21:21 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_map(t_data *data, int fd)
{
	t_lst	*maplst;
	t_lst	*tmp_map;
	int		a;

	maplst = store_map(fd);
	if (!maplst)
		return (1);
	tmp_map = maplst;
	while (tmp_map)
	{
		a = ft_strlen(tmp_map->mapline);
		if (store_path(data, tmp_map, a))
			break ;
		tmp_map = tmp_map->next;
	}
	if (check_path(data))
		return (free_all(data), free_lstmap(maplst), err_msg(MAP_INV, NULL, 2));
	if (store_map_data(data, tmp_map) || is_player(data, data->map.map)
		|| verif_data(data->map.map))
		return (free_all(data), free_lstmap(maplst),
			err_msg(MAP_INV, NULL, 1), 3);
	free_lstmap(maplst);
	return (0);
}

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

int	store_path(t_data *data, t_lst *maplst, int a)
{
	if (!maplst || !maplst->mapline)
		return (1);
	if (ft_strncmp(maplst->mapline, "NO ", 3))
	{
		if (data->path.path_n)
			return (2);
		data->path.path_n = ft_strndup((maplst->mapline + 3), (a - 4));
		data->path.path_n = ft_strtrim(data->path.path_n, ' ');
	}
	else if (ft_strncmp(maplst->mapline, "SO ", 3))
	{
		if (data->path.path_s)
			return (2);
		data->path.path_s = ft_strndup(maplst->mapline + 3, (a - 4));
		data->path.path_s = ft_strtrim(data->path.path_s, ' ');
	}
	else
		return (store_path_2(data, maplst, a));
	return (0);
}

int	store_path_2(t_data *data, t_lst *maplst, int a)
{
	if (ft_strncmp(maplst->mapline, "WE ", 3))
	{
		if (data->path.path_w)
			return (2);
		data->path.path_w = ft_strndup(maplst->mapline + 3, (a - 4));
		data->path.path_w = ft_strtrim(data->path.path_w, ' ');
	}
	else if (ft_strncmp(maplst->mapline, "EA ", 3))
	{
		if (data->path.path_e)
			return (2);
		data->path.path_e = ft_strndup(maplst->mapline + 3, (a - 4));
		data->path.path_e = ft_strtrim(data->path.path_e, ' ');
	}
	else if (ft_strncmp(maplst->mapline, "F ", 2))
	{
		if (data->path.path_f)
			return (2);
		data->path.path_f = ft_strndup(maplst->mapline + 2, (a - 3));
		data->path.path_f = ft_strtrim(data->path.path_f, ' ');
	}
	else
		return (store_path_3(data, maplst, a));
	return (0);
}

int	store_path_3(t_data *data, t_lst *maplst, int a)
{
	if (ft_strncmp(maplst->mapline, "C ", 2))
	{
		if (data->path.path_c)
			return (2);
		data->path.path_c = ft_strndup(maplst->mapline + 2, (a - 3));
		data->path.path_c = ft_strtrim(data->path.path_c, ' ');
	}
	else if (maplst->mapline[0] != '\n')
		return (3);
	return (0);
}
