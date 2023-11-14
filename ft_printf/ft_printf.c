/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:18:54 by randre            #+#    #+#             */
/*   Updated: 2023/10/30 09:37:41 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_printf_loop(va_list args, const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			i++;
			str++;
		}
		else
		{
			str++;
			if (ft_isvalid_arg(*str) && *str != '%')
				i += ft_typecheck(*str, args);
			else
			{
				write(1, str, 1);
				i++;
			}
			str++;
		}
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	if (!str)
		return (0);
	va_start(args, str);
	i = ft_printf_loop(args, str);
	va_end(args);
	return (i);
}
