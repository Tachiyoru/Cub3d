/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:07:12 by sleon             #+#    #+#             */
/*   Updated: 2023/04/05 15:18:33 by msharifi         ###   ########.fr       */
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
		return (free_all(&data), 2);
	free_all(&data);
	return (0);
}
