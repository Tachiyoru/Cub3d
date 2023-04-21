/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:58:07 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/21 15:11:43 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_or_door_too_close(t_data *d, double new[2], char c)
{
	if (c == 'W')
	{
		if (d->map.map[(int)(d->ray.pos[Y] + d->ray.dir[Y] * 0.2)][(int)new[X]]
				== '1' || d->map.map[(int)(d->ray.pos[Y]
					+ d->ray.dir[Y] * 0.2)][(int)new[X]] == 'D')
			return (1);
		if (d->map.map[(int)new[Y]][(int)(d->ray.pos[X] + d->ray.dir[X] * 0.2)]
			== '1' || d->map.map[(int)new[Y]][(int)(d->ray.pos[X]
				+ d->ray.dir[X] * 0.2)] == 'D')
			return (1);
	}
	else if (c == 'S')
	{
		if (d->map.map[(int)(d->ray.pos[Y] - d->ray.dir[Y] * 0.2)][(int)new[X]]
				== '1' || d->map.map[(int)(d->ray.pos[Y]
					- d->ray.dir[Y] * 0.2)][(int)new[X]] == 'D')
			return (1);
		if (d->map.map[(int)new[Y]][(int)(d->ray.pos[X] - d->ray.dir[X] * 0.2)]
			== '1' || d->map.map[(int)new[Y]][(int)(d->ray.pos[X]
				- d->ray.dir[X] * 0.2)] == 'D')
			return (1);
	}
	return (wall_or_door_too_close2(d, c));
}

int	wall_or_door_too_close2(t_data *d, char c)
{
	if (c == 'A')
	{
		if (d->map.map[(int)(d->ray.pos[Y])][(int)(d->ray.pos[X]
			+ d->ray.dir[Y] * 0.2)] == '1' || d->map.map[(int)(d->ray.pos[Y])]
				[(int)(d->ray.pos[X] + d->ray.dir[Y] * 0.2)] == 'D')
			return (1);
		if (d->map.map[(int)(d->ray.pos[Y] - d->ray.dir[X] * 0.2)]
			[(int)(d->ray.pos[X])] == '1' || d->map.map[(int)(d->ray.pos[Y]
				- d->ray.dir[X] * 0.2)][(int)(d->ray.pos[X])] == 'D')
			return (1);
	}
	else if (c == 'D')
	{
		if (d->map.map[(int)(d->ray.pos[Y])][(int)(d->ray.pos[X]
			- d->ray.dir[Y] * 0.2)] == '1' || d->map.map[(int)(d->ray.pos[Y])]
				[(int)(d->ray.pos[X] - d->ray.dir[Y] * 0.2)] == 'D')
			return (1);
		if (d->map.map[(int)(d->ray.pos[Y] + d->ray.dir[X] * 0.2)]
			[(int)(d->ray.pos[X])] == '1' || d->map.map[(int)(d->ray.pos[Y]
				+ d->ray.dir[X] * 0.2)][(int)(d->ray.pos[X])] == 'D')
			return (1);
	}
	return (0);
}

void	update_pos(t_data *data, double newpos[2])
{
	data->player[POS_X] = newpos[X];
	data->player[POS_Y] = newpos[Y];
	data->ray.pos[X] = newpos[X];
	data->ray.pos[Y] = newpos[Y];
}

void	ray_collision(t_ray *ray, t_map *map)
{
	float	dist;

	if (map->map[ray->map[Y]][ray->map[X]] == '1')
			ray->hit = 1;
	else if (map->map[ray->map[Y]][ray->map[X]] == 'P' && ray->moose_click == 1)
	{
		map->map[ray->map[Y]][ray->map[X]] = 'D';
		ray->moose_click = 0;
		ray->hit = 1;
	}
	else if (map->map[ray->map[Y]][ray->map[X]] == 'D')
	{
		dist = (ray->sidedist[X] - ray->deltadist[X]);
		if (ray->moose_click == 1 && dist < 0.8)
		{
			map->map[ray->map[Y]][ray->map[X]] = 'P';
			ray->moose_click = 0;
		}
		else
		{
			ray->hit = 1;
			ray->door = 1;
		}
	}
}
