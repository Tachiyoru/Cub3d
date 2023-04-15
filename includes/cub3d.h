/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:41:17 by sleon             #+#    #+#             */
/*   Updated: 2023/04/15 17:31:50 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "error.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>

# define PATH_F "images/floor.xpm"
# define PATH_C "images/ceil.xpm"
# define PATH_D "images/door.xpm"
# define PATH_X "images/oui.xpm"

# define K_ESC			65307
# define K_UP			65362
# define K_DOWN			65364
# define K_LEFT			65361
# define K_RIGHT		65363
# define K_A			97
# define K_W			119
# define K_S			115
# define K_D			100

# define Y 0
# define X 1

# define SCREEN_WIDTH	1500
# define SCREEN_HEIGHT	900
# define M_PI			3.14159265358979323846

enum	e_player
{
	POS_Y,
	POS_X,
	POS_PXL_X,
	POS_PXL_Y,
	ANGLE,
	MAX_POS,
};

enum	e_img
{
	WALL_NORTH,
	WALL_SOUTH,
	WALL_WEST,
	WALL_EAST,
	DOOR,
	FLOOR,
	CEIL,
	RENDU,
	SURPRISE,
	MAX_IMG,
};

/****************************/
/*			 GNL			*/
/****************************/

# define BUFFER_SIZE 10

char	*get_next_line(int fd, int reset);
char	*ft_read_line(int fd, char *line);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *line, char *buff);
char	*ft_line_to_buff(char *line);
char	*ft_read_new_line(char *line);

/****************************/
/*			STRUCTS			*/
/****************************/

typedef struct s_map
{
	int		size_x;
	int		size_y;
	char	**map;
}t_map;

typedef struct s_path
{
	char	*path_n;
	char	*path_s;
	char	*path_w;
	char	*path_e;
	char	*path_f;
	char	*path_c;
	char	*path_d;
	int		color_c;
	int		color_f;
}t_path;

typedef struct s_image
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}t_image;

typedef struct s_ray
{
	float		pos[2];
	float		dir[2];
	float		plan[2];
	float		raydir[2];
	float		cam_x;
	int			map[2];
	float		sidedist[2];
	float		deltadist[2];
	int			step[2];
	int			door;
	int			hit;
	int			side;
	float		paperwalldist;
	float		lineheight;
	float		drawstart;
	float		drawend;
}t_ray;

typedef struct s_text
{
	int			texdir;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
}	t_text;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		player[MAX_POS];
	int			mouse_pos;
	int			q;
	double		player_speed;
	t_image		img[MAX_IMG];
	t_path		path;
	t_map		map;
	t_text		text;
	t_ray		ray;
}t_data;

typedef struct s_lst
{
	char			*mapline;
	struct s_lst	*next;
}t_lst;


void	fc_casting_2(t_data *data, int y, float *floor, float *floorstep);

/****************************************************/
/*						FCTS						*/
/****************************************************/

////****************** ERROR *******************////

// error.c
int		err_msg(char *s1, char *s2, int ret_val);

////****************** FREE *******************////

// free_mlx.c
void	destroy_images(t_data *data);
void	destroy_all(t_data *data);

// free.c
void	ft_free(void *addr);
void	free_lstmap(t_lst *lst_map);
void	free_path(t_path img);
void	free_all(t_data *data);
void	free_tab(char **tab, int n);
////****************** GAME *******************////

// mini_map.c
void	convert_map_minimap(t_data *data, int y, int x);
void	print_box(t_data *data, int y, int x, int color);

// moves.c
void	move_cam(t_data *data, double mouv);
void	move_player(t_data *data, char c);
void	update_pos(t_data *data, double newpos[2]);
int 	mouse_move(int x, int y, t_data *data);

// raycasting.c
void	raycasting(t_data *data);
void	cam_pos(t_ray *ray, int screen_width, int x);
void	ray_dist(t_ray *ray);
void	dda_algo(t_ray *ray, t_map *map);
void	wall_lenght(t_ray *ray, int screen_height);

// render.c
int		render(t_data *data);
void	print_background(t_data *data);
void	init_walls(t_ray *ray, t_text *text);
void	draw_wall(t_data *data, int x0, t_ray *ray, t_text *text);

////****************** INIT *******************////

// init_map.c
int		init_map(t_data *data, int fd);
t_lst	*store_map(int fd);
int		store_path(t_data *data, t_lst *maplst, int a);
int		store_path_2(t_data *data, t_lst *maplst, int a);
int		store_path_3(t_data *data, t_lst *maplst, int a);

// init_mlx.c
void	init_player(t_data *data);
int		check_screen_size(t_data *data);
int		init_mlx(t_data *data);
void	loop_hook(t_data data);

// init_rgb.c
int		init_rgb(t_data *data);
int		check_tab(char **tab);
int		make_rgb(int r, int g, int b);

// init_to_null.c
void	init_txturs_to_null(t_data *data);
void	init_to_null_data(t_data *data);
void	init_to_null_img(t_data *data);

// init_txturs.c
int		init_rendu(t_data *data);
int		init_images(t_data *data);
int		init_textures(t_data *data);

////***************** KEYPRESS ****************////

// keypress.c
int		handle_keypress(int keysym, t_data *data);
int		handle_btnrealease(t_data *data);

////***************** PARSING *****************////

// check_ext.c
int		check_ext(char *file, char *str);
int		check_open(t_path img);
void	close_txtures(int *fd);

// check_map.c
int		check_path(t_data *data);
int		check_map(t_data *data, char *file);
int		check_wall(char **map);
char	**create_copy_map(char **map);

// check_txturs.c
int		check_textures_size(t_path img);
int		sizing(void *mlx, void *img_ptr, char *path);

// data_map.c
int		store_map_data(t_data *data, t_lst *tmp_map);
int		verif_data(char **map);
int		verif_char(t_lst *check, t_lst *tmp_map);

// parsing_map.c
int		is_player(t_data *data, char **map);
int		return_is_player(int p);
void	set_value(t_data *data, char c, int i, int j);
void	set_value_2(t_data *data, char c);
int		check_around(char **map, int y, int x);

////****************** UTILS ******************////

// alloc.c
void	*ft_calloc(size_t n, size_t size);

// lst_utils.c
t_lst	*ft_lstnew(char *str);
t_lst	*ft_lstlast(t_lst *lst);
int		ft_lstsize(t_lst *lst);

// split.c
int		word_count(char *str, char set);
int		char_count(char *str, char set, int pos);
char	*ft_putword(char *str, char *tab, char set, int pos);
char	**ft_split(char	*str, char set);

// str_utils.c
int		ft_strlen(char *str);
char	*ft_strtrim(char *str, char c);
char	*ft_strndup(char *str, int n);
int		ft_strncmp(char *str, char *to_find, int n);
int		ft_strchr2(char *str, char c);

// utils.c
long	ft_atoi(char *str);
int		is_digit(char *str);

#endif
