/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:45:10 by sleon             #+#    #+#             */
/*   Updated: 2023/04/05 19:07:47 by msharifi         ###   ########.fr       */
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
	data->map.size_y = ft_lstsize(tmp_map);
	data->map.map = ft_calloc(data->map.size_y + 1, sizeof(char *));
	data->map.map[data->map.size_y] = NULL;
	if (!data->map.map)
		return (1);
	i = -1;
	while (tmp_map)
	{
		data->map.map[++i] = ft_strndup(tmp_map->mapline,
				(ft_strlen(tmp_map->mapline) - 1));
		if (data->map.size_x < (ft_strlen(tmp_map->mapline) - 1))
			data->map.size_x = (ft_strlen(tmp_map->mapline) - 1);
		if (!data->map.map[i])
			return (1);
		tmp_map = tmp_map->next;
	}
	return (0);
}

int	verif_data(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ')
				return (1);
		}
	}
	return (0);
}
