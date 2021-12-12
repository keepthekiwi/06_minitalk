/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:38:55 by skillian          #+#    #+#             */
/*   Updated: 2021/09/02 20:15:44 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
/*
** https://openbook.rheinwerk-verlag.de/c_von_a_bis_z/018_c_stdarg_h_001.htm
** va_start & end has to be outside of the while loop
*/
{
	va_list	arg;
	int		numofchar;

	numofchar = 0;
	va_start(arg, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			numofchar = numofchar + ft_convert(*s, arg);
			if (!(*s))
				break ;
		}
		else
			numofchar += ft_putchar(*s);
		s++;
	}
	va_end(arg);
	return (numofchar);
}
