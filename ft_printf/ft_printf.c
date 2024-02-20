/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:41:39 by ebensalt          #+#    #+#             */
/*   Updated: 2021/12/03 03:26:30 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	fpurs2(const char format, va_list p, int j)
{
	if (format == 'p')
	{
		ft_putstr("0x");
		j = ft_puthexap(va_arg(p, unsigned long), "0123456789abcdef");
		j += 2;
	}
	return (j);
}

int	fpurs1(const char format, va_list p)
{
	int	j;

	j = 0;
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(p, int), 1);
		j++;
	}
	if (format == 's')
		j = ft_putstr(va_arg(p, char *));
	if (format == 'd' || format == 'i')
		j = ft_putnbr(va_arg(p, int));
	if (format == '%')
	{
		ft_putchar_fd('%', 1);
		j++;
	}
	if (format == 'u')
		j = ft_putunbr(va_arg(p, int));
	if (format == 'x')
		j = ft_puthexa(va_arg(p, unsigned int), "0123456789abcdef");
	if (format == 'X')
		j = ft_puthexa(va_arg(p, unsigned int), "0123456789ABCDEF");
	j = fpurs2(format, p, j);
	return (j);
}

int	printchr(const char format, int j)
{
	if (format != '%')
	{
		ft_putchar_fd(format, 1);
		j++;
	}
	return (j);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		k;
	int		a;
	va_list	p;

	i = 0;
	j = 0;
	a = 0;
	va_start(p, format);
	while (format[i] != '\0')
	{
		j = printchr(format[i], j);
		if (format[i] == '%')
		{
			while (format[i + 1] == ' ')
				i++;
			k = fpurs1(format[i + 1], p);
			a = k + a;
			i++;
		}
		i++;
	}
	va_end(p);
	return (j + a);
}
