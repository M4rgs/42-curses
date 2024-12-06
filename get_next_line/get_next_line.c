/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:06:46 by tamounir          #+#    #+#             */
/*   Updated: 2024/12/06 20:06:47 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reading(char *buffer, int fd)
{
	char	*buff;
	int		readed;

	readed = 1;
	while (!ft_strchr(buffer) && readed != 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		readed = read(fd, buff, BUFFER_SIZE);
		if ((!buffer && readed == 0) || readed == -1)
		{
			free (buff);
			buff = NULL;
			return (NULL);
		}
		buff[readed] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	return (buffer);
}

char	*get_rest(char *buffer, char *line)
{
	char	*rest;
	int		i;
	int		j;

	i = ft_strlen(line);
	if (!buffer[i])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	j = 0;
	while (buffer[i++])
		j++;
	rest = malloc(j + 1);
	if (!rest)
		return (NULL);
	i = ft_strlen(line);
	j = 0;
	while (buffer[i])
		rest[j++] = buffer[i++];
	rest[j] = '\0';
	free(buffer);
	return (rest);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		line = malloc(i + 1);
	if (buffer[i] == '\n')
		line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= MAX_INT)
		return (NULL);
	temp = reading(buff, fd);
	if (!temp)
	{
		if (buff)
			free(buff);
		buff = NULL;
		return (NULL);
	}
	buff = temp;
	line = get_line(buff);
	buff = get_rest(buff, line);
	return (line);
}
