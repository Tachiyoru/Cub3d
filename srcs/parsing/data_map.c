/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:45:10 by sleon             #+#    #+#             */
/*   Updated: 2023/04/05 13:36:56 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	store_map_data(t_data *data, t_lst *tmp_map)
{
	int		i;
	t_lst	*check;

	check = tmp_map;
	if (verif_char(check))
		return (1);
	while (tmp_map->mapline[0] == '\n')
		tmp_map = tmp_map->next;
	data->map.map = ft_calloc((ft_lstsize(tmp_map) + 1), sizeof(char *));
	data->map.size_y = ft_lstsize(tmp_map);
	if (!data->map.map)
		return (1);
	i = -1;
	while (tmp_map)
	{
		data->map.map[++i] = ft_strndup (tmp_map->mapline,
				(ft_strlen(tmp_map->mapline) - 1));
		if (data->map.size_x < (ft_strlen(tmp_map->mapline) - 1))
			data->map.size_x = (ft_strlen(tmp_map->mapline) - 1);
		if (!data->map.map[i])
			return (1);
		tmp_map = tmp_map->next;
	}
	return (0);
}
//probleme ligne 25 repercute dans le print

int	verif_char(t_lst *check)
{
	int	i;

	while (check)
	{
		i = 0;
		while (check->mapline[i])
		{
			if (check->mapline[i] == ' ' || check->mapline[i] == '0'
				|| check->mapline[i] == '1' || check->mapline[i] == '\n')
				i++;
			else if (check->mapline[i] == 'N' || check->mapline[i] == 'S'
				|| check->mapline[i] == 'W' || check->mapline[i] == 'E')
				i++;
			else
				return (err_msg(MAP_INV, NULL, 1));
		}
		check = check->next;
	}
	return (0);
}
