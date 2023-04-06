/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:41:17 by sleon             #+#    #+#             */
/*   Updated: 2023/04/06 16:26:12 by msharifi         ###   ########.fr       */
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

typedef struct s_image
{
	char	*path_n;
	char	*path_s;
	char	*path_w;
	char	*path_e;
	char	*path_f;
	char	*path_c;
}t_image;

typedef struct s_player
{
	int		start_x;
	int		start_y;
}t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		image;
	t_map		map;
	t_player	player;
}t_data;

typedef struct s_lst
{
	char			*mapline;
	struct s_lst	*next;
}t_lst;

void	print_lstmap(t_lst *lst);
void	print_path(t_data *data);
void	print_tab(char **tab);

/****************************************************/
/*						FCTS						*/
/****************************************************/

////****************** ERROR *******************////

// error.c
int		err_msg(char *s1, char *s2, int ret_val);

////****************** FREE *******************////

// free_mlx.c
int		destroy_all(t_data *data);

// free.c
void	ft_free(void *addr);
void	free_lstmap(t_lst *lst_map);
void	free_path(t_image img);
void	free_all(t_data *data);
void	free_tab(char **tab, int n);

////****************** INIT *******************////

// init_mlx.c
int		init_mlx(t_data *data);
void	loop_hook(t_data data);

// init_map.c
int		init_map(t_data *data, int fd);
t_lst	*store_map(int fd);
int		store_path(t_data *data, t_lst *maplst, int a);
int		store_path_2(t_data *data, t_lst *maplst, int a);
int		check_path(t_data *data);

// init_to_null.c
void	init_to_null_data(t_data *data);
void	init_to_null_img(t_data *data);

////***************** KEYPRESS ****************////

// keypress.c
int		handle_keypress(int keysym, t_data *data);
int		handle_btnrealease(t_data *data);

////***************** PARSING *****************////

//check_map.c
int		check_map(t_data *data, char *file);
int		check_ext(char *file, char *str);
int		check_open(t_image img);
void	close_txtures(int *fd);
char	**create_copy_map(char **map);

// data_map.c
int		store_map_data(t_data *data, t_lst *tmp_map);
int		verif_data(char **map);

// parsing_map.c
int		is_player(t_data *data, char **map);
int		return_is_player(int p);
int		verif_char(t_lst *check);
int		check_wall(char **map);
int		check_around(char **map, int y, int x);

////****************** UTILS ******************////

// alloc.c
void	*ft_calloc(size_t n, size_t size);

// lst_utils.c
t_lst	*ft_lstnew(char *str);
t_lst	*ft_lstlast(t_lst *lst);
int		ft_lstsize(t_lst *lst);

// str_utils.c
int		ft_strlen(char *str);
char	*ft_strndup(char *str, int n);
int		ft_strncmp(char *str, char *to_find, int n);
int		ft_strchr2(char *str, char c);

#endif
