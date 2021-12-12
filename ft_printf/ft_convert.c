/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:07:05 by skillian          #+#    #+#             */
/*   Updated: 2021/09/02 20:24:00 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(char s, va_list arg)
/*
** %% percent sign
** %c single character
** https://stackoverflow.com/questions/28054194/char-type-in-va-arg
** va_arg has to be min type int
** %s string of characters
** char transfers first character, char * full string
** %p The void * pointer argument is printed in hexadecimal (also Adresse Ptr)
** %d decimal (base 10) number
** %i integer in base 10
** %u unsigned decimal (base 10) number
** %x number in hexadecimal (base 16)
*/
{
	int	i;

	if (s == '%')
		return (ft_putchar('%'));
	if (s == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (s == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (s == 'p')
	{
		i = write(1, "0x", 2);
		return (i + ft_dectohex((unsigned long long)va_arg(arg, void *), s));
	}
	if (s == 'i' || s == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (s == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	if (s == 'x' || s == 'X')
		return (ft_dectohex(va_arg(arg, unsigned int), s));
	return (0);
}
