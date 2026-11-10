/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisella <kisella@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:43:28 by kisella           #+#    #+#             */
/*   Updated: 2026/11/10 16:21:54 by kisella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_translate(const char type, va_list *arg)
{
	if (type == 'c')
		return (ft_putchar(va_arg(*arg, int)));
	if (type == 'u')
		return (ft_putbase(va_arg(*arg, unsigned int), "0123456789"));
	if (type == 's')
		return (ft_putstr(va_arg(*arg, char *)));
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(*arg, int)));
	if (type == 'x')
		return (ft_putbase(va_arg(*arg, unsigned int), "0123456789abcdef"));
	if (type == 'X')
		return (ft_putbase(va_arg(*arg, unsigned int), "0123456789ABCDEF"));
	if (type == 'p')
		return (ft_putptr(va_arg(*arg, void *)));
	if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	ft_handle(const char *format, int *i, va_list *args)
{
	if (format[*i] == '%')
	{
		if (format[*i + 1] == '\0')
			return (-1);
		(*i)++;
		return (ft_translate(format[*i], args));
	}
	return (ft_putchar(format[*i]));
}

int	ft_printf(const char *, ...)
{
}
