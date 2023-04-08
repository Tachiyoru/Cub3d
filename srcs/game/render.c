/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:37:07 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/08 21:11:34 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_data *data)
{
	data->player[POS_X] += 0.5f;
	data->player[POS_Y] += 0.5f;
	data->player[POS_PXL_X] = data->player[POS_X] * 64;
	data->player[POS_PXL_Y] = data->player[POS_Y] * 64;
	data->delta[0] = cos(data->player[ANGLE]) * 5;
	data->delta[1] = sin(data->player[ANGLE]) * 5;
}

int	render(t_data *data)
{
	init_player(data);
	return (0);
}
