/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:37:00 by sleon             #+#    #+#             */
/*   Updated: 2023/04/04 16:29:21 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *line, char *buff)
{
	char			*str;
	size_t			i;
	size_t			j;

	if (!line)
	{
		line = (char *)ft_calloc(sizeof(char), 1);
		line[0] = '\0';
	}
	if (!line || !buff)
		return (NULL);
	str = ft_calloc((ft_strlen(line) + ft_strlen(buff) + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (line)
		while (line[++i] != '\0')
			str[i] = line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(line) + ft_strlen(buff)] = '\0';
	free(line);
	return (str);
}

char	*ft_line_to_buff(char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	s = (char *)ft_calloc((i + 2), sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		s[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		s[i] = line[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_read_new_line(char *line)
{
	int		j;
	int		i;
	char	*s;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free (line);
		return (NULL);
	}
	s = (char *)ft_calloc((ft_strlen(line) - i + 1), 1);
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (line [i])
		s[j++] = line[i++];
	s[j] = '\0';
	free(line);
	return (s);
}
