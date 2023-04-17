/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:44:33 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/04 15:47:43 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*tab;
	char	*str;

	tab = malloc(n * size);
	if (!tab)
		return (NULL);
	str = tab;
	while (n > 0)
	{
		n--;
		str[n] = '\0';
	}
	return (tab);
}
