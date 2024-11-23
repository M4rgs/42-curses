/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:43:48 by tamounir          #+#    #+#             */
/*   Updated: 2024/11/22 18:43:50 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	res;

	res = 0;
	if (nb > 9)
	{
		res += ft_putnbr_unsigned(nb / 10);
		res += ft_putnbr_unsigned(nb % 10);
	}
	else
		res += ft_putchar(nb + 48);
	return (res);
}
