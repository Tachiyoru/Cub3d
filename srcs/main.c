/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:07:12 by sleon             #+#    #+#             */
/*   Updated: 2023/04/11 16:28:49 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
	// print_tab(data.map.map);

// mlx_get_screen_size(cub3d->game.mlx, &cub3d->sizex, &cub3d->sizey);dans crete_window

int	main(int ac, char **av)
{
	t_data	data;

	data = (t_data){0};
	if (ac != 2)
		return (err_msg(ARG_START, NULL, 1));
	if (check_map(&data, av[1]))
		return (2);
	if (init_mlx(&data))
		return (free_all(&data), 3);
	loop_hook(data);
	mlx_destroy_display(data.mlx_ptr);
	ft_free(data.mlx_ptr);
	free_all(&data);
	return (0);
}
