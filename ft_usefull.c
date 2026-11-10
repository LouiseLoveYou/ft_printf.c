/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usefull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisella <kisella@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:44:13 by kisella           #+#    #+#             */
/*   Updated: 2026/11/10 15:46:09 by kisella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) == -1)
		{
			return (-1);
		}
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
	{
		return (-1);
	}
	return (1);
}

int	ft_putnbr(int nb)
{
	int		count;
	int		ret;
	char	c;

	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	count = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		ret = ft_putnbr(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = (nb % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putptr(void *ptr)
{
	int	count;
	int	ret;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count = (ft_putstr("0x"));
	if (count == -1)
		return (-1);
	ret = ft_putbase((unsigned long) ptr, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	return (count + ret);
}

int	ft_putbase(unsigned long nb, char *base)
{
	int				count;
	int				ret;
	char			c;
	unsigned long	len;

	len = 0;
	count = 0;
	while (base[len] != '\0')
	{
		len++;
	}
	if (nb >= len)
	{
		ret = ft_putbase(nb / len, base);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = base[nb % len];
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}
