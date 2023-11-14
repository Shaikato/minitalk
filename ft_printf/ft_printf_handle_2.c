/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:45:22 by randre            #+#    #+#             */
/*   Updated: 2023/10/28 07:53:52 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_phandle(va_list args)
{
	size_t	nbr;

	nbr = va_arg(args, size_t);
	if (!nbr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
	{
		write(1, "0x", 2);
		return (ft_hexa(nbr, "0123456789abcdef") + 2);
	}
}
