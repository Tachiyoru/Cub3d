/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:00:49 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/15 17:25:45 by sleon            ###   ########.fr       */
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

void	free_path(t_path img)
{
	ft_free(img.path_n);
	ft_free(img.path_s);
	ft_free(img.path_w);
	ft_free(img.path_e);
}

void	free_all(t_data *data)
{
	free_path(data->path);
	free_tab(data->map.map, 0);
	destroy_all(data);
}

// Free un char **, si n == 0 en etierete, sinon jusqu'a n
void	free_tab(char **tab, int n)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i] && (i < n || n == 0))
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
}
