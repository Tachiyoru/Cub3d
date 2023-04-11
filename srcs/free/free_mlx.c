/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:40:30 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/11 18:32:07 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_images(t_data *data)
{
	if (data->img[WALL_NORTH].img)
		mlx_destroy_image(data->mlx_ptr, data->img[WALL_NORTH].img);
	data->img[WALL_NORTH].img = NULL;
	if (data->img[WALL_SOUTH].img)
		mlx_destroy_image(data->mlx_ptr, data->img[WALL_SOUTH].img);
	data->img[WALL_SOUTH].img = NULL;
	if (data->img[WALL_WEST].img)
		mlx_destroy_image(data->mlx_ptr, data->img[WALL_WEST].img);
	data->img[WALL_WEST].img = NULL;
	if (data->img[WALL_EAST].img)
		mlx_destroy_image(data->mlx_ptr, data->img[WALL_EAST].img);
	data->img[WALL_EAST].img = NULL;
	if (data->img[RENDU].img)
		mlx_destroy_image(data->mlx_ptr, data->img[RENDU].img);
	data->img[RENDU].img = NULL;
}

void	destroy_all(t_data *data)
{
	destroy_images(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		ft_free(data->mlx_ptr);
	}
}
