/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_txturs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:46:41 by sleon             #+#    #+#             */
/*   Updated: 2023/04/08 20:42:18 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	check_textures_size(t_path img)
// {
// 	void	*img_ptr;
// 	// void	*mlx;

// 	// mlx = mlx_init();
// 	img_ptr = NULL;
// 	if (sizing(mlx, img_ptr, img.path_n))
// 		return (1);
// 	if (sizing(mlx, img_ptr, img.path_s))
// 		return (1);
// 	if (sizing(mlx, img_ptr, img.path_w))
// 		return (1);
// 	if (sizing(mlx, img_ptr, img.path_e))
// 		return (1);
// 	return (0);
// }

// int	sizing(void *mlx, void *img_ptr, char *path)
// {
// 	int		x;
// 	int		y;

// 	x = 0;
// 	y = 0;
// 	img_ptr = mlx_xpm_file_to_img(mlx, path, &x, &y);
// 	if (!img_ptr || x != 64 || y != 64)
// 	{
// 		mlx_destroy_img(mlx, img_ptr);
// 		return (1);
// 	}
// 	mlx_destroy_img(mlx, img_ptr);
// }
