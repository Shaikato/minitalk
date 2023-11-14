/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:42:36 by randre            #+#    #+#             */
/*   Updated: 2023/11/13 14:36:54 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig)
{
	static int	c;
	static int	bit;

	if (sig == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Too many arguments, aborting...\n");
		return (1);
	}
	ft_printf("%d\n", (int)getpid());
	while (argc == 1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
	return (0);
}
