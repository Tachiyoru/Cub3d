/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:26:56 by sleon             #+#    #+#             */
/*   Updated: 2023/04/08 18:48:47 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_rc(t_data *data)
{
	int		x;
	float	ra;
	// double	dist[2];
	// double	end_pos[2][2];

	init_rc_to_null(&data->rc);
	// init_player(data);
	x = 0;
	ra = data->player.angle - ((1 * PI / 180) * 30);
	// calculate ray position and direction
	while (42)
	{
		while (x < WIDTH_SCREEN)
		{
			data->rc.camera_x = 2 * x / WIDTH_SCREEN - 1;
			data->rc.raydir_x = data->rc.v_dir_x + data->rc.plan_x * data->rc.camera_x;
			data->rc.raydir_y = data->rc.v_dir_y + data->rc.plan_y * data->rc.camera_x;
			x++;
		}
		// which box of the map we're in
		int map_x = (int)data->player.pos_x;
		int map_y = (int)data->player.pos_y;

		// length of ray from current position to next x or y-side
		double side_dist_x;
		double side_dist_y;
		
		// length of ray from one x or y-side to next x or y-side
		data->rc.d_dist_x = sqrt(1 + (data->rc.raydir_y * data->rc.raydir_y) / (data->rc.raydir_x * data->rc.raydir_x));
		data->rc.d_dist_y = sqrt(1 + (data->rc.raydir_x * data->rc.raydir_x) / (data->rc.raydir_y * data->rc.raydir_y));
		
		// what direction to step in x or y-direction (either +1 or -1)
		int step_x;
		int step_y;

		// calculate step and initial sideDist
		if (data->rc.raydir_x < 0)
		{
			step_x = -1;
			side_dist_x = (data->player.pos_x - map_x) * data->rc.d_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - data->player.pos_x) * data->rc.d_dist_x;
		}
		if (data->rc.raydir_y < 0)
		{
			step_y = -1;
			side_dist_y = (data->player.pos_y - map_y) * data->rc.d_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - data->player.pos_y) * data->rc.d_dist_y;
		}
		// perform DDA
		while (data->rc.hit == 0)
		{
			// jump to next map square, either in x-direction, or in y-direction
			if (side_dist_x < side_dist_y)
			{
			side_dist_x += data->rc.d_dist_x;
			map_x += step_x;
			data->rc.side = 0;
			}
			else
			{
			side_dist_y += data->rc.d_dist_y;
			map_y += step_y;
			data->rc.side = 1;
			}
			// Check if ray has hit a wall
			if (data->map.map[map_x][map_y] == '1')
				data->rc.hit = 1;
		}
		// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (data->rc.side == 0)
			data->rc.perp_wall_dist = side_dist_x - data->rc.d_dist_x;
		else
			data->rc.perp_wall_dist = side_dist_y - data->rc.d_dist_y;
		// Calculate height of line to draw on screen
		data->rc.line_height = (int)(HEIGHT_SCREEN / data->rc.perp_wall_dist);

		// Calculate lowest and highest pixel to fill in current stripe
		data->rc.draw_start = - data->rc.line_height / 2 + HEIGHT_SCREEN / 2;
		if (data->rc.draw_start < 0)
			data->rc.draw_start = 0;
		data->rc.draw_end = data->rc.line_height / 2 + HEIGHT_SCREEN / 2;
		if (data->rc.draw_end >= HEIGHT_SCREEN)
			data->rc.draw_end = HEIGHT_SCREEN - 1;
		//choose wall color
		int	color;
		if (data->map.map[map_y][map_x] == '1')
			color = data->image.color_c;
		else
			color = data->image.color_f;
		// //give x and y sides different brightness
		// if (side == 1)
		// 	color = color / 2;
		//draw the pixels of the stripe as a vertical line
	}
	return (0);
}

void	init_walls(t_data *data)
{
	if (data->rc.side == 0 && data->rc.raydir_x < 0)
		data->rc.txt_dir = 0;
	if (data->rc.side == 0 && data->rc.raydir_x >= 0)
		data->rc.txt_dir = 1;
	if (data->rc.side == 1 && data->rc.raydir_y < 0)
		data->rc.txt_dir = 2;
	if (data->rc.side == 1 && data->rc.raydir_y >= 0)
		data->rc.txt_dir = 3;
	if (data->rc.side == 0)
		data->rc.txt_width = data->player.pos_y + data->rc.perp_wall_dist * data->rc.raydir_y;
	else
		data->rc.txt_width = data->player.pos_x + data->rc.perp_wall_dist * data->rc.raydir_x;
	data->rc.txt_width -= floor(data->rc.txt_width);
}

void	draw_wall(t_data *data, int x0, int start_wall, int end_wall) 
{
	int		j;
	double	step;
	double	txt_pos;
	int		width_txt;
	int		height_txt;

	init_walls(data);
	j = start_wall;
	width_txt =(int)(data->rc.txt_width * (float)WIDTH_IMG);
	if (data->rc.side == 0 && data->rc.raydir_x > 0)
		width_txt = WIDTH_IMG - width_txt - 1;
	if (data->rc.side == 1 && data->rc.raydir_y < 0)
		width_txt = WIDTH_IMG - width_txt - 1;
	step = 1.0 * HEIGHT_IMG / data->rc.line_height;

	txt_pos = (start_wall - HEIGHT_SCREEN / 2 + data->rc.line_height / 2) * step;
	while (j < end_wall)
	{
		height_txt = (int)txt_pos & (HEIGHT_IMG - 1);
		txt_pos += step;
		if (j < HEIGHT_SCREEN && x0 < WIDTH_SCREEN)
			data->image.addr[j * data->img.line_len / 4 + x0] = data->txt[data->rc.txt_dir].addr[height_txt * data->txt[0].line_len / 4 + width_txt];
		j++;
	}
}

void	draw(t_data *data, int x0, int start_wall, int end_wall) 
{
	int	j;

	j = 0;
	while (j < start_wall)
	{
		data->image.addr[j * data->img.line_len / 4 + x0] = data->txt->floor;
		j++;
	}
	if (j <= end_wall)
		draw_wall(data, x0, start_wall, end_wall);
	j = end_wall - 1;
	while (j < HEIGHT_SCREEN)
	{
		data->image.addr[j * data->img.line_len / 4 + x0] = data->txt->cell;
		j++;
	}
}

// void	init_player(t_data *data)
// {
// 	// data->player.pos_x += 0.5f;
// 	// data->player.pos_y += 0.5f;
// 	data->player.pixel_x = data->player.pos_x * 64;
// 	data->player.pixel_y = data->player.pos_y * 64;
// 	data->delta[0] = cos(data->player.angle) * 5;
// 	data->delta[1] = sin(data->player.angle) * 5;
// }

void	ray_pos(t_data *data)
{
	int	x;

	x = 0;
	data->rc.hit = 0;
	data->rc.perp_wall_dist = 0;
	data->rc.line_height = 0;
	while (x < WIDTH_SCREEN)
	{
		init_rc(data);
		draw(data, x, data->rc.draw_start, data->rc.draw_end);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.mlx_img, 0, 0);
}
