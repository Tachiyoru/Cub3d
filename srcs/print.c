/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:44:02 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/04 17:06:10 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_lstmap(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	if (!lst)
		return ;
	while (tmp)
	{
		printf("%s", tmp->mapline);
		tmp = tmp->next;
	}
}
