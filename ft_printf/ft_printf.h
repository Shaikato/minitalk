/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:56:59 by randre            #+#    #+#             */
/*   Updated: 2023/10/24 15:56:44 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

unsigned int	ft_strlen(const char *str);
int				ft_printf(const char *str, ...);
int				ft_isvalid_arg(const char c);
int				ft_chandle(va_list args);
int				ft_shandle(va_list args);
int				ft_dhandle(va_list args);
int				ft_uhandle(va_list args);
int				ft_typecheck(const char c, va_list args);
int				ft_putnbr(int n);
char			*ft_strdup(const char *s);
int				ft_xhandle(va_list args, size_t i);
int				ft_xcount(size_t nbr);
int				ft_putnbr_long(unsigned int n);
int				ft_hexa(size_t nbr, char *base_str);
int				ft_phandle(va_list args);
int				ft_nbrlen(int nbr);

#endif
