/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:53:11 by tamounir          #+#    #+#             */
/*   Updated: 2024/10/27 20:47:59 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rtrn(int signe)
{
	if (signe < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		odd;
	size_t	rzlt;

	i = 0;
	odd = 1;
	rzlt = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			odd = odd * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((rzlt > MAX_LL / 10)
			|| (rzlt == MAX_LL / 10 && (str[i] - 48) > MAX_LL % 10))
			return (ft_rtrn(odd));
		rzlt = rzlt * 10 + (str[i] - 48);
		i++;
	}
	return (rzlt * odd);
}
