/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:13:21 by tamounir          #+#    #+#             */
/*   Updated: 2024/11/21 11:13:22 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	res;

	res = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (nb < 0)
	{
		res += ft_putchar('-');
		nb = -nb;
		res += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		res += ft_putnbr(nb / 10);
		res += ft_putnbr(nb % 10);
	}
	else if (nb <= 9)
		res += ft_putchar(nb + 48);
	return (res);
}
