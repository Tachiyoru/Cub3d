/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:20:18 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/07 15:18:24 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(t_data *data, char **map)
{
	int	i;
	int	j;
	int	p;

	i = -1;
	p = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				p++;
				set_value(data, map[i][j], i, j);
			}
		}
	}
	return (return_is_player(p));
}

void	set_value(t_data *data, char c, int i, int j)
{
	if (c == 'N')
		data->player.angle = PI / 2;
	else if (c == 'S')
		data->player.angle = 1.5 * PI;
	else if (c == 'E')
		data->player.angle = PI * 2;
	else if (c == 'W')
		data->player.angle = 0;
	data->map.map[i][j] = '0';
	data->player.pos_y = i;
	data->player.pos_x = j;
}

int	return_is_player(int p)
{
	if (p < 1)
		return (err_msg(NO_PLAYER, NULL, 1));
	else if (p > 1)
		return (err_msg(TOO_PLAYER, NULL, 1));
	return (0);
}

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
				return (1);
		}
		check = check->next;
	}
	return (0);
}

// Return 0 si la map est entouree de 1 sinon 0
int	check_wall(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
				if (check_around(map, y, x))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_around(char **map, int y, int x)
{
	if (x + 1 >= ft_strlen(map[y]) && (map[y][x + 1] != '1'
		&& map[y][x + 1] != '0'))
		return (1);
	else if (x - 1 < 0 || ((map[y][x - 1] != '1' && map[y][x - 1] != '0')))
		return (1);
	else if (x >= ft_strlen(map[y + 1])
		|| (map[y + 1][x] != '1' && map[y + 1][x] != '0'))
		return (1);
	else if ((x > ft_strlen(map[y - 1])
			|| (map[y - 1][x] != '1' && map[y - 1][x] != '0')))
		return (1);
	return (0);
}
