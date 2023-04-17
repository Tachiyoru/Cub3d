/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_txturs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:46:41 by sleon             #+#    #+#             */
/*   Updated: 2023/04/17 18:16:26 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures_size(t_path img)
{
	void	*img_ptr;
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		return (err_msg(MLX, NULL, 1));
	img_ptr = NULL;
	if (check_all_size(img, mlx, img_ptr))
		return (2);
	mlx_destroy_display(mlx);
	ft_free(mlx);
	return (0);
}

int	check_all_size(t_path img, void *mlx, void *img_ptr)
{
	if (sizing(mlx, img_ptr, img.path_n))
		return (mlx_destroy_display(mlx), ft_free(mlx),
			err_msg(img.path_n, IMG_SIZE, 1));
	if (sizing(mlx, img_ptr, img.path_s))
		return (mlx_destroy_display(mlx), ft_free(mlx),
			err_msg(img.path_s, IMG_SIZE, 2));
	if (sizing(mlx, img_ptr, img.path_w))
		return (mlx_destroy_display(mlx), ft_free(mlx),
			err_msg(img.path_w, IMG_SIZE, 3));
	if (sizing(mlx, img_ptr, img.path_e))
		return (mlx_destroy_display(mlx), ft_free(mlx),
			err_msg(img.path_e, IMG_SIZE, 4));
	if (sizing(mlx, img_ptr, img.path_f))
		return (mlx_destroy_display(mlx), ft_free(mlx),
			err_msg(img.path_f, IMG_SIZE, 5));
	if (sizing(mlx, img_ptr, img.path_c))
		return (mlx_destroy_display(mlx), ft_free(mlx),
			err_msg(img.path_c, IMG_SIZE, 6));
	return (0);
}

int	sizing(void *mlx, void *img_ptr, char *path)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	img_ptr = mlx_xpm_file_to_image(mlx, path, &x, &y);
	if (!img_ptr)
		return (1);
	else if (x != 64 || y != 64)
		return (mlx_destroy_image(mlx, img_ptr), 1);
	mlx_destroy_image(mlx, img_ptr);
	return (0);
}
