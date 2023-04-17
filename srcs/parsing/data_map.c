/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:45:10 by sleon             #+#    #+#             */
/*   Updated: 2023/04/17 18:09:57 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	store_map_data(t_data *data, t_lst *tmp_map)
{
	int		i;
	t_lst	*check;

	check = tmp_map;
	if (verif_char(check, tmp_map))
		return (1);
	data->map.size_y = ft_lstsize(tmp_map);
	data->map.map = ft_calloc(data->map.size_y + 1, sizeof(char *));
	data->map.map[data->map.size_y] = NULL;
	if (!data->map.map)
		return (1);
	i = -1;
	while (tmp_map)
	{
		if (tmp_map->mapline[ft_strlen(tmp_map->mapline) - 1] == '\n')
			tmp_map->mapline[ft_strlen(tmp_map->mapline) - 1] = '\0';
		data->map.map[++i] = ft_strndup(tmp_map->mapline,
				(ft_strlen(tmp_map->mapline)));
		if (data->map.size_x < (ft_strlen(tmp_map->mapline)))
			data->map.size_x = (ft_strlen(tmp_map->mapline));
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
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != ' ' && map[i][j] != 'D')
				return (1);
		}
	}
	return (0);
}

int	verif_char(t_lst *check, t_lst *tmp_map)
{
	int	i;

	while (tmp_map->mapline[0] == '\n')
		tmp_map = tmp_map->next;
	while (check)
	{
		i = 0;
		while (check->mapline[i])
		{
			if (check->mapline[i] == ' ' || check->mapline[i] == '0'
				|| check->mapline[i] == '1' || check->mapline[i] == '\n'
				|| check->mapline[i] == 'D')
				i++;
			else if (check->mapline[i] == 'N' || check->mapline[i] == 'S'
				|| check->mapline[i] == 'W' || check->mapline[i] == 'E')
				i++;
			else
				return (1);
		}
		check = check->next;
	}
	return (0);
}
