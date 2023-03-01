/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-bas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 05:40:31 by yoel-bas          #+#    #+#             */
/*   Updated: 2023/02/19 05:41:57 by yoel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	int				result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	hand(int seg)
{
	(void)seg;
	write(1, "done", 4);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 3)
	{
		if (atoi(av[1]) <= 0)
			exit (0);
		j = 0;
		while (av[2][j])
		{
			i = 7;
			while (i >= 0)
			{
				if (av[2][j] & 1 << i)
					kill(atoi(av[1]), SIGUSR1);
				else
					kill(atoi(av[1]), SIGUSR2);
				i--;
				usleep(500);
			}
			j++;
		}
	}
	return (0);
}
