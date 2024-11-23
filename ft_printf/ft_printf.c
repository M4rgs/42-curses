/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:17:02 by tamounir          #+#    #+#             */
/*   Updated: 2024/11/21 10:17:06 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_format(char specify, va_list args)
{
	int	count;

	count = 0;
	if (specify == '%')
		count += ft_putchar('%');
	else if (specify == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specify == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (specify == 'd' || specify == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (specify == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (specify == 'x' || specify == 'X')
		count += put_hexa(va_arg(args, unsigned int), specify);
	else if (specify == 'p')
		count += ft_print_address(va_arg(args, unsigned long));
	else if (specify == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(specify);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		rtr;
	va_list	args;

	i = 0;
	rtr = 0;
	va_start(args, format);
	if (write(1, "", 0) < 0)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			rtr += printf_format(format[++i], args);
			i++;
		}
		else
		{
			rtr += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (rtr);
}
