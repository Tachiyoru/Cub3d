/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:52:16 by sleon             #+#    #+#             */
/*   Updated: 2023/04/21 15:20:15 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ARG_START	"Run as : ./cub3d map"
# define NOT_CUM	" : map is not a .cub"
# define XPM		" : failed to convert into xpm"
# define NOT_XPM	" : texture is not a .xpm"
# define OPEN		" : open failed"
# define MALLOC		"Malloc failed"
# define MAP_INV	"Invalid map"
# define OPEN_TXTUR	"Could not open all the textures"
# define WALLS		"Map is not closed by walls"
# define RGB		"RGB given are incorrect"
# define NO_PLAYER	"No player in map"
# define TOO_PLAYER	"Too many players in map"
# define INIT_IMG	"mlx_init_image failed"
# define DATA_ADDR	"mlx_get_data_addr failed"
# define IMG_SIZE	" : image of wrong size"
# define MLX		"mlx_init failed"
# define SCREEN		"Window size too big"

#endif
