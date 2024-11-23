/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:53:10 by tamounir          #+#    #+#             */
/*   Updated: 2024/11/21 18:54:57 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int n)
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

static void	ft_putnbr_hex_up(unsigned int n)
{
	char	*hex_digits;

	hex_digits = "0123456789ABCDEF";
	if (n >= 16)
		ft_putnbr_hex_up(n / 16);
	ft_putchar(hex_digits[n % 16]);
}

static void	ft_putnbr_hex_lo(unsigned int n)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_hex_lo(n / 16);
	ft_putchar(hex_digits[n % 16]);
}

int	put_hexa(unsigned int n, const char format)
{
	int	lenthg;

	lenthg = hex_len(n);
	if (n == 0)
		lenthg++;
	if (format == 'x')
	{
		ft_putnbr_hex_lo(n);
	}
	else if (format == 'X')
	{
		ft_putnbr_hex_up(n);
	}
	return (lenthg);
}
