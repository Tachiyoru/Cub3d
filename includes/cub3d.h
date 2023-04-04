/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:41:17 by sleon             #+#    #+#             */
/*   Updated: 2023/03/25 17:52:00 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "error.h"
// # include "mlx/mlx.h"
// # include "mlx/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define K_ESC			65307
# define K_UP			65362
# define K_DOWN			65364
# define K_LEFT			65361
# define K_RIGHT		65363
# define K_A			97
# define K_W			119
# define K_S			115
# define K_D			100

/****************************/
/*			STRUCTS			*/
/****************************/

typedef struct s_map
{
	int		size_x;
	int		size_y;
	int		collectible;
	int		ennemy;
	int		player;
	int		exit;
	int		lines;
	char	**map;

}t_map;

typedef struct s_image
{
	void	*mlx_img;
	void	*wall;
	void	*exit;
	void	*exit_o;
	void	*ground;
	void	*player;
	void	*monstre;
	void	*monstre2;
	void	*item;
}t_image;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		exit_x;
	int		exit_y;
	int		collected;
	int		open_exit;
	int		move_count;
	int		anim_frame;
}t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_lentgh;
	t_image		image;
	t_map		map;
	t_player	player;
}t_data;

typedef struct s_lst
{
	char			*mapline;
	struct s_lst	*next;
}t_lst;

/****************************/
/*			FCTS			*/
/****************************/

//check_map
int		check_map(t_data *data, char *file);
int		check_cub(char *file);

#endif
