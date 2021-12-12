/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:03:22 by skillian          #+#    #+#             */
/*   Updated: 2021/09/01 21:38:59 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printf(const char *s, ...);
int			ft_convert(char s, va_list arg);
int			ft_dectohex(unsigned long long dec, char s);
int			ft_nbrlen(long long n);
int			ft_putchar(char c);
int			ft_putnbr(long long n);
int			ft_putstr(char *s);
size_t		ft_strlen(const char *str);

#endif