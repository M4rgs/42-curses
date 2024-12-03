/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 02:34:34 by tamounir          #+#    #+#             */
/*   Updated: 2024/12/03 02:34:38 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buffer)
{
	char	*buff;
	int		readed;

	readed = 1;
	while (!ft_strchr(buffer) && readed != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		readed = (int)read(fd, buff, BUFFER_SIZE);
		if ((!buffer && readed == 0) || readed == -1)
			return (free(buff), NULL);
		buff[readed] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
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

char	*ft_get_rest(char *buffer, char *line)
{
	char	*rest;
	int		i;
	int		j;

	i = ft_strlen(line);
	if (!buffer[i])
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i++])
		j++;
	rest = malloc(sizeof(char) * (j + 1));
	if (!rest)
		return (NULL);
	i = ft_strlen(line);
	j = 0;
	while (buffer[i])
		rest[j++] = buffer[i++];
	rest[j] = '\0';
	return (free(buffer), rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= MAX_INT)
		return (NULL);
	temp = read_file(fd, buffer);
	if (!temp)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = temp;
	line = ft_get_line(buffer);
	buffer = ft_get_rest(buffer, line);
	return (line);
}
