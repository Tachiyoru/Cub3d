/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:00:49 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/04 19:27:39 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(void *addr)
{
	if (addr)
		free(addr);
	addr = NULL;
}

void	free_lstmap(t_lst *lst_map)
{
	t_lst	*before;

	if (!lst_map)
		return ;
	before = lst_map;
	while (lst_map)
	{
		lst_map = lst_map->next;
		ft_free(before->mapline);
		ft_free(before);
		before = lst_map;
	}
}

void	free_img(t_image img)
{
	ft_free(img.path_n);
	ft_free(img.path_s);
	ft_free(img.path_w);
	ft_free(img.path_e);
	ft_free(img.path_f);
	ft_free(img.path_c);
}

void	free_all(t_data *data)
{
	free_img(data->image);
}
