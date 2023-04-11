/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:44:02 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/11 14:14:40 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_path(t_data *data)
{
	printf("%s\n", data->path.path_n);
	printf("%s\n", data->path.path_s);
	printf("%s\n", data->path.path_w);
	printf("%s\n", data->path.path_e);
	printf("%s\n", data->path.path_f);
	printf("%s\n", data->path.path_c);
}

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

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("%s\n", tab[i]);
}
