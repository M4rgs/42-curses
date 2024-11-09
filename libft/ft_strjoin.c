/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:10:42 by tamounir          #+#    #+#             */
/*   Updated: 2024/11/02 20:37:42 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	lent;
	size_t	i;

	if (!s2)
		return (p = ft_strdup(s1));
	if (!s1)
		return (p = ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	lent = ft_strlen(s1) + ft_strlen (s2);
	p = malloc(lent + 1);
	if (!p)
		return (NULL);
	i = 0;
	if (s1)
		i += ft_strlcpy(&p[i], s1, ft_strlen(s1) + 1);
	if (s2)
		i += ft_strlcpy(&p[i], s2, ft_strlen(s2) + 1);
	p[i] = '\0';
	return (p);
}
