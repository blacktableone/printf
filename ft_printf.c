/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzu <zuzu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:22:46 by zuzu              #+#    #+#             */
/*   Updated: 2026/02/19 23:55:20 by zuzu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char specifier, va_list *args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (specifier == 'p')
		count += ft_putptr(va_arg(*args, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(*args, int));
	else if (specifier == 'u')
		count += ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (specifier == 'x')
		count += ft_puthex(va_arg(*args, unsigned int), 'x');
	else if (specifier == 'X')
		count += ft_puthex(va_arg(*args, unsigned int), 'X');
	else if (specifier == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(specifier);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_handle_format(format[i + 1], &args);
			i += 2;
		}
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end (args);
	return (count);
}
