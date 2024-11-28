/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:24:39 by tamounir          #+#    #+#             */
/*   Updated: 2024/11/28 17:24:40 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (p == 0)
		return (p);
	ft_bzero(p, nmemb * size);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	int		s1len;
	int		s2len;
	int		i;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	newstring = calloc(s1len + s2len +1, sizeof(char));
	if (!newstring)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		newstring[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		newstring[s1len + i] = s2[i];
	newstring[s1len + i] = '\0';
	return (newstring);
}

void	ft_bzero(void *s, size_t n)
{
	char	*char_ptr;
	size_t	i;

	char_ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		char_ptr[i] = '\0';
		i++;
	}
}
