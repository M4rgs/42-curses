/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:14:26 by tamounir          #+#    #+#             */
/*   Updated: 2024/11/03 01:30:58 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordss(const char *s, char c)
{
	int	word;
	int	i;
	int	f;

	i = 0;
	f = 0;
	word = 0;
	while (s[i] > 0)
	{
		if (s[i] != c)
		{
			if (f == 0 && s[i] != c)
				word++;
			f = 1;
		}
		else
			f = 0;
		i++;
	}
	return (word);
}

static char	*ft_add(const char *str, int last, int start)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((last - start + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (start < last)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	dfn(size_t *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = -1;
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	i;
	int		j;
	int		first_index;

	if (!s)
		return (NULL);
	p = malloc((wordss(s, c) + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	dfn(&i, &j, &first_index);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && first_index < 0)
			first_index = i;
		else if ((s[i] == c || ft_strlen(s) == i) && first_index >= 0)
		{
			p[j] = ft_add(s, i, first_index);
			j++;
			first_index = -1;
		}
		i++;
	}
	p[j] = NULL;
	return (p);
}
