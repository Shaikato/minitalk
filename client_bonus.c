/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:42:31 by randre            #+#    #+#             */
/*   Updated: 2024/02/02 10:45:17 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <limits.h>

static int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long		val;

	i = 1;
	val = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		val *= 10;
		val += *str - '0';
		str++;
		if (val > LLONG_MAX && i > 0)
			return (-1);
		if (val > LLONG_MAX && i < 0)
			return (0);
	}
	return (val * i);
}

static void	ft_receive(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Confirmation received !\n");
	else
		ft_printf("Confirmation received !\n");
}

void	ft_btoa(int s_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	s_pid;

	if (argc != 3)
		return (0);
	s_pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		signal(SIGUSR1, &ft_receive);
		signal(SIGUSR2, &ft_receive);
		ft_btoa(s_pid, *argv[2]);
		argv[2]++;
	}
	return (0);
}
