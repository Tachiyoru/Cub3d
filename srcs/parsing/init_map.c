/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:06:57 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/04 17:10:02 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_map(t_data *data, int fd)
{
	t_lst	*maplst;
	(void)data;
	maplst = store_map(fd);
	if (!maplst)
		return (1);
	//met tout le fd dans une t_lst pour pas faire plusieurs ouverture de fd

	//check wall
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
		return (NULL);
	tmp = ft_lstnew(line);
	map_lst = tmp;
	if (!tmp)
		return (NULL);
	while (line)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		ft_lstlast(tmp)->next = ft_lstnew(line);
	}
	print_lstmap(map_lst);
	return (map_lst);
}
