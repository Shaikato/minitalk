/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:33:11 by randre            #+#    #+#             */
/*   Updated: 2023/10/30 09:56:01 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_chandle(va_list args)
{
	char	c;

	c = (char) va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_shandle(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		write(1, str, ft_strlen(str));
		return (ft_strlen(str));
	}
}

int	ft_dhandle(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	return (ft_putnbr(nbr));
}

int	ft_uhandle(va_list args)
{
	unsigned int	nbrr;

	nbrr = va_arg(args, unsigned int);
	return (ft_putnbr_long(nbrr));
}

int	ft_xhandle(va_list args, size_t i)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	if (i == 0)
		return (ft_hexa(nbr, "0123456789abcdef"));
	else
		return (ft_hexa(nbr, "0123456789ABCDEF"));
}
