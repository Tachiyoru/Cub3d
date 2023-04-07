/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:40:30 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/07 18:11:18 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_images(t_data *data)
{
	if (data->txt[0].img)
		mlx_destroy_image(data->mlx_ptr, data->txt[0].img);
	data->txt[0].img = NULL;
	if (data->txt[1].img)
		mlx_destroy_image(data->mlx_ptr, data->txt[1].img);
	data->txt[1].img = NULL;
	if (data->txt[2].img)
		mlx_destroy_image(data->mlx_ptr, data->txt[2].img);
	data->txt[2].img = NULL;
	if (data->txt[3].img)
		mlx_destroy_image(data->mlx_ptr, data->txt[3].img);
	data->txt[3].img = NULL;
}

int	destroy_all(t_data *data)
{
	destroy_images(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	return (0);
}
