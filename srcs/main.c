/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:07:12 by sleon             #+#    #+#             */
/*   Updated: 2023/03/25 17:16:01 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int ac, char *av)
{
	t_data	data;

	data = (t_data){0};
	if (ac != 2)
		return (write(2, "Run as : ./so_long map\n", 24), EXIT_FAILURE);
	if (!check_map(&data, av[1]))
		return (2);
}
