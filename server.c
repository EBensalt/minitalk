/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:08:57 by ebensalt          #+#    #+#             */
/*   Updated: 2022/07/24 00:42:34 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	hundler(int sig)
{
	static char	i;
	static int	j;
	static int	k;

	if (j == 0)
		j = 1;
	if (sig == SIGUSR1)
	{
		i = i | j;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		j = j << 1;
		k++;
	}
	if (k == 8)
	{
		write(1, &i, 1);
		i = 0;
		j = 1;
		k = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, hundler);
	signal(SIGUSR2, hundler);
	while (1)
		pause();
}
