/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:07:12 by sleon             #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2023/04/08 19:27:44 by msharifi         ###   ########.fr       */
=======
/*   Updated: 2023/04/07 15:51:52 by msharifi         ###   ########.fr       */
>>>>>>> parent of 697c86b ([CLEAN] sans rc)
=======
/*   Updated: 2023/04/07 15:51:52 by msharifi         ###   ########.fr       */
>>>>>>> parent of 697c86b ([CLEAN] sans rc)
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	// print_tab(data.map.map);
	loop_hook(data);
	mlx_destroy_display(data.mlx_ptr);
	ft_free(data.mlx_ptr);
	free_all(&data);
	return (0);
}
