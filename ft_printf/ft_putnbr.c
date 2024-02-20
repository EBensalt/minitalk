/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 00:31:43 by ebensalt          #+#    #+#             */
/*   Updated: 2021/12/02 01:28:43 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	count(int n)
{
	int				a;
	unsigned int	b;

	a = 0;
	if (n < 0)
		b = n * -1;
	else
		b = n;
	while (b / 10 > 0)
	{
		a++;
		b = b / 10;
	}
	if (n < 0)
		return (a + 2);
	return (a + 1);
}

void	nbr(int n, char a)
{
	a = n + '0';
	write(1, &a, 1);
}

int	ft_putnbr(int n)
{
	char	a;
	int		i;

	i = count(n);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = n * -1;
		}
		if (n / 10 > 0)
		{
			ft_putnbr(n / 10);
			a = n % 10 + '0';
			write(1, &a, 1);
		}
		if (n >= 0 && n <= 9)
			nbr(n, a);
	}
	return (i);
}
