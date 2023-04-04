/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:41:17 by sleon             #+#    #+#             */
/*   Updated: 2023/04/04 17:10:17 by msharifi         ###   ########.fr       */
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
/*			 GNL			*/
/****************************/

# define BUFFER_SIZE 10

char		*get_next_line(int fd, int reset);
char		*ft_read_line(int fd, char *line);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *line, char *buff);
char		*ft_line_to_buff(char *line);
char		*ft_read_new_line(char *line);

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
	void	*mlx_img;
	void	*wall;
	void	*ground;
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

void	print_lstmap(t_lst *lst);

/****************************************************/
/*						FCTS						*/
/****************************************************/

////****************** FREE *******************////

// free.c
void	ft_free(void *addr);
void	free_lstmap(t_lst *lst_map);

////***************** PARSING *****************////

//check_map.c
int		check_map(t_data *data, char *file);
int		check_cub(char *file);

// init_map.c
int		init_map(t_data *data, int fd);
t_lst	*store_map(int fd);

////****************** UTILS ******************////

// alloc.c
void	*ft_calloc(size_t n, size_t size);

// lst_utils.c
t_lst	*ft_lstnew(char *str);
t_lst	*ft_lstlast(t_lst *lst);
int		ft_lstsize(t_lst *lst);


// str_utils.c
int		ft_strlen(char *str);

#endif
