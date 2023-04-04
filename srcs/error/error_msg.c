/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:21:36 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/04 18:23:44 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_msg(char *s1, char *s2, int ret_val)
{
	if (s1)
		write(STDOUT_FILENO, s1, ft_strlen(s1));
	if (s2)
		write(STDOUT_FILENO, s2, ft_strlen(s2));
	write(STDOUT_FILENO, "\n", 1);
	return (ret_val);
}
