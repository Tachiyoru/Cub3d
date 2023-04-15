/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:53:25 by msharifi          #+#    #+#             */
/*   Updated: 2023/04/11 19:58:30 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

// Free str
// Retourne la chaine de caractere sans le ou les plusieurs cacaracteres c
// au debut et a la fin de str ou NULL en cas d'echec
char	*ft_strtrim(char *str, char c)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (str[i] == c)
		i++;
	j = ft_strlen(str) - 1;
	if (j <= 0)
		return (ft_free(str), NULL);
	while (str[j] == c)
		j--;
	if (i > j)
		return (ft_free(str), NULL);
	res = ft_strndup(str + i, j - i + 1);
	if (!res)
		return (ft_free(str), NULL);
	ft_free(str);
	return (res);
}

// Duplique n caratcere de str
// Si n = 0 duplique l'entierte de str
// Return la chaine de caractere dupliquee
char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*dup;

	i = -1;
	if (!str)
		return (NULL);
	dup = ft_calloc(ft_strlen(str) + 1, 1);
	if (!dup)
		return (NULL);
	if (n == 0)
	{
		while (str[++i])
			dup[i] = str[i];
	}
	else
	{
		while (++i < n && str[i])
			dup[i] = str[i];
	}
	return (dup);
}

// Return 1 si les n premiers carac de str et to_find sont les memes, sinon 0
int	ft_strncmp(char *str, char *to_find, int n)
{
	int	i;

	i = 0;
	if (!str || !to_find)
		return (0);
	while (str[i] && to_find[i] && str[i] == to_find[i] && i < n)
		i++;
	if (i == n)
		return (1);
	return (0);
}

// Cherche c dans str
// Return 1 si c est dans str, sinon 0
int	ft_strchr2(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}
