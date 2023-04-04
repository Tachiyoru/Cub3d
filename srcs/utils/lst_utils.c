/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:12:14 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/04 16:23:48 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_lst	*ft_lstnew(char *str)
{
	t_lst	*node;

	node = ft_calloc(1, sizeof(t_lst));
	if (!node)
		return (NULL);
	node->mapline = str;
	node->next = NULL;
	return (node);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	t_lst	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

int	ft_lstsize(t_lst *lst)
{
	t_lst	*last;
	int		i;

	i = 0;
	last = lst;
	if (!lst)
		return (0);
	while (last)
	{
		last = last->next;
		i++;
	}
	return (i);
}
