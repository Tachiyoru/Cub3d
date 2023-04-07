/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:26:56 by sleon             #+#    #+#             */
/*   Updated: 2023/04/07 17:38:47 by msharifi         ###   ########.fr       */
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
		double perpWallDist;
		
		// what direction to step in x or y-direction (either +1 or -1)
		int step_x;
		int step_y;
		int hit = 0; // was there a wall hit?
		int side; // was a NS or a EW wall hit?

		// calculate step and initial sideDist
		if (data->rc.raydir_x < 0)
		{
			step_x = -1;
			side_dist_x = (data->player.pos_x- map_x) * data->rc.d_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - data->player.pos_x) * data->rc.d_dist_x;
		}
		if (data->rc.raydir_y < 0)
		{
			step_y = -1;
			side_dist_y = (data->player.pos_y- map_y) * data->rc.d_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - data->player.pos_y) * data->rc.d_dist_y;
		}
		// perform DDA
		while (hit == 0)
		{
			// jump to next map square, either in x-direction, or in y-direction
			if (side_dist_x < side_dist_y)
			{
			side_dist_x += data->rc.d_dist_x;
			map_x += step_x;
			side = 0;
			}
			else
			{
			side_dist_y += data->rc.d_dist_y;
			map_y += step_y;
			side = 1;
			}
			// Check if ray has hit a wall
			if (data->map.map[map_x][map_y] == '1')
				hit = 1;
		}
		// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0)
			perpWallDist = side_dist_x - data->rc.d_dist_x;
		else
			perpWallDist = side_dist_y - data->rc.d_dist_y;
		// Calculate height of line to draw on screen
		int lineHeight = (int)(HEIGHT_SCREEN / perpWallDist);

		// Calculate lowest and highest pixel to fill in current stripe
		int	drawStart = -lineHeight / 2 + HEIGHT_SCREEN / 2;
		if (drawStart < 0)
			drawStart = 0;
		int	drawEnd = lineHeight / 2 + HEIGHT_SCREEN / 2;
		if (drawEnd >= HEIGHT_SCREEN)
			drawEnd = HEIGHT_SCREEN - 1;
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
		// draw(x, drawStart, drawEnd, color);
	}
	return (0);
}

// void	draw_wall(t_cub3d *cub3d, int x0, int start_wall, int end_wall) 
// {
// 	int	j;

// 	init_walls(cub3d);
// 	j = start_wall;
// 	cub3d->text.texx =(int)(cub3d->text.wallx * (float)IMG_WIDTH);
// 	if (cub3d->ray.side == 0 && cub3d->ray.raydir_x > 0)
// 		cub3d->text.texx = IMG_WIDTH - cub3d->text.texx - 1;
// 	if (cub3d->ray.side == 1 && cub3d->ray.raydir_y < 0)
// 		cub3d->text.texx = IMG_WIDTH - cub3d->text.texx - 1;
// 	cub3d->text.step = 1.0 * IMG_LENGTH / cub3d->ray.lineheight;

// 	cub3d->text.texpos = (start_wall - cub3d->screen_height / 2 + cub3d->ray.lineheight / 2) * cub3d->text.step;
// 	while (j < end_wall)
// 	{
// 		cub3d->text.texy = (int)cub3d->text.texpos & (IMG_LENGTH - 1);
// 		cub3d->text.texpos += cub3d->text.step;
// 		if (j < cub3d->screen_height && x0 < cub3d->screen_width)
// 			cub3d->img.addr[j * cub3d->img.line_len / 4 + x0] = cub3d->texture[cub3d->text.texdir].addr[cub3d->text.texy * cub3d->texture[0].line_len / 4 + cub3d->text.texx];
// 		j++;
// 	}
// }

// void	draw(t_data *data, int x0, int start_wall, int end_wall) 
// {
// 	int	j;

// 	j = 0;
// 	while (j < start_wall)
// 	{
// 		data->image.addr[j * data->image.line_len / 4 + x0] = data->image.floor;
// 		j++;
// 	}
// 	// if (j <= end_wall)
// 	// 	draw_wall(data, x0, start_wall, end_wall);
// 	j = end_wall - 1;
// 	while (j < data->screen_height)
// 	{
// 		data->image.addr[j * data->image.line_len / 4 + x0] = data->image.cell;
// 		j++;
// 	}
// }

// void	init_player(t_data *data)
// {
// 	// data->player.pos_x += 0.5f;
// 	// data->player.pos_y += 0.5f;
// 	data->player.pixel_x = data->player.pos_x * 64;
// 	data->player.pixel_y = data->player.pos_y * 64;
// 	data->delta[0] = cos(data->player.angle) * 5;
// 	data->delta[1] = sin(data->player.angle) * 5;
// }
