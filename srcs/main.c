/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:07:12 by sleon             #+#    #+#             */
/*   Updated: 2023/04/12 17:13:18 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// mlx_get_screen_size(cub3d->game.mlx, &cub3d->sizex, &cub3d->sizey);
// dans crete_window

int	main(int ac, char **av)
{
	t_data	data;

	data = (t_data){0};
	if (ac != 2)
		return (err_msg(ARG_START, NULL, 1));
	init_to_null_data(&data);
	if (check_map(&data, av[1]))
		return (2);
	if (init_mlx(&data))
		return (free_all(&data), 3);
	loop_hook(data);
	(void)av;
	free_all(&data);
	return (0);
}
