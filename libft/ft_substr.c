/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:52:22 by tamounir          #+#    #+#             */
/*   Updated: 2024/11/03 22:48:42 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	sln;
	size_t	end;

	if (!s)
		return (NULL);
	end = 0;
	sln = ft_strlen(s);
	if (start < sln)
		end = sln - start;
	if (end > len)
		end = len;
	end = end + 1;
	p = malloc(end);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s + start, end);
	return (p);
}
