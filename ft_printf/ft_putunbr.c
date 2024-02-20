/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 03:40:18 by ebensalt          #+#    #+#             */
/*   Updated: 2021/12/01 22:17:44 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	count(unsigned int n)
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

int	ft_putunbr(unsigned int n)
{
	char	a;
	int		i;

	i = count(n);
	if (n / 10 > 0)
	{
		ft_putunbr(n / 10);
		a = n % 10 + '0';
		write(1, &a, 1);
	}
	if (n >= 0 && n <= 9)
	{
		a = n + '0';
		write(1, &a, 1);
	}
	return (i);
}
