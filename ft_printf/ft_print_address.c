/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:43:38 by tamounir          #+#    #+#             */
/*   Updated: 2024/11/23 15:12:19 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	ft_putnbr_hex_lo(unsigned long n)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_hex_lo(n / 16);
	ft_putchar(hex_digits[n % 16]);
}

int	ft_print_address(unsigned long n)
{
	int	lenthg;

	lenthg = hex_len(n);
	if (n == 0)
		lenthg++;
	lenthg += ft_putstr("0x");
	ft_putnbr_hex_lo(n);
	return (lenthg);
}
