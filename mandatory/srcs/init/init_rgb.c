/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:19:17 by sleon             #+#    #+#             */
/*   Updated: 2023/04/21 13:33:35 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_rgb(t_data *data)
{
	char	**tab;
	int		tab_int[3];

	tab = ft_split(data->path.path_c, ',');
	if (check_tab(tab))
		return (free_tab(tab, 0), 1);
	tab_int[0] = ft_atoi(tab[0]);
	tab_int[1] = ft_atoi(tab[1]);
	tab_int[2] = ft_atoi(tab[2]);
	data->path.color_c = make_rgb(tab_int[0], tab_int[1], tab_int[2]);
	free_tab(tab, 0);
	tab = ft_split(data->path.path_f, ',');
	if (check_tab(tab))
		return (free_tab(tab, 0), 1);
	tab_int[0] = ft_atoi(tab[0]);
	tab_int[1] = ft_atoi(tab[1]);
	tab_int[2] = ft_atoi(tab[2]);
	data->path.color_f = make_rgb(tab_int[0], tab_int[1], tab_int[2]);
	free_tab(tab, 0);
	return (0);
}

int	check_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (is_digit(tab[i]))
			return (1);
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
