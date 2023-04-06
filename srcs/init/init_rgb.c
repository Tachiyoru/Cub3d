/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:19:17 by sleon             #+#    #+#             */
/*   Updated: 2023/04/06 16:49:49 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//char **tab
//int tab[3]
//int res

//split f et c dans le tab en 2 fois
//check les conditions 3valeur aucune supperieur a 255
// atoi les 3 valeur dans le tableau dint
//creer la couleur rgb a partir du tableau d'int
//storer dans data

int	init_rgb(t_data *data)
{
	char	**tab;
	int		tab_int[3];

	tab = ft_split(data->image.path_c, ',');
	if (check_tab(tab))
		return (free_tab(tab, 0), 1);
	tab_int[0] = ft_atoi(tab[0]);
	tab_int[1] = ft_atoi(tab[1]);
	tab_int[2] = ft_atoi(tab[2]);
	data->image.color_c = make_rgb(tab_int[0], tab_int[1], tab_int[2]);
	free_tab(tab, 0);
	tab = ft_split(data->image.path_f, ',');
	if (check_tab(tab))
		return (free_tab(tab, 0), 1);
	tab_int[0] = ft_atoi(tab[0]);
	tab_int[1] = ft_atoi(tab[1]);
	tab_int[2] = ft_atoi(tab[2]);
	data->image.color_f = make_rgb(tab_int[0], tab_int[1], tab_int[2]);
	free_tab(tab, 0);
	return (0);
}

int	check_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			return (1);
		if (ft_strlen(tab[i]) > 3)
			return (1);
		if (i > 3)
			return (1);
	}
	return (0);
}

int	make_rgb(int r, int g, int b)
{
	return (r * 65536 + g * 256 + b);
}
