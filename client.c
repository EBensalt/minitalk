/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:32:51 by ebensalt          #+#    #+#             */
/*   Updated: 2022/07/24 01:25:33 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(int e)
{
	if (e != 0)
		write(2, "error\n", 6);
	exit(e);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	if (ac != 3)
		ft_error(1);
	i = -1;
	while (av[2][++i])
	{
		j = -1;
		k = 1;
		while (++j < 8)
		{
			if ((av[2][i] & k) == k)
				kill(ft_atoi(av[1]), SIGUSR1);
			else
				kill(ft_atoi(av[1]), SIGUSR2);
			usleep(500);
			k = k << 1;
		}
	}
}
