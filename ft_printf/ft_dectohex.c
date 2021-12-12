/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:14:31 by skillian          #+#    #+#             */
/*   Updated: 2021/09/02 20:50:42 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_end(int *i, char *reversedigit)
{
	int	c;

	c = *i;
	*i -= 1;
	while (*i >= 0)
	{
		write(1, &reversedigit[*i], 1);
		*i -= 1;
	}
	return (c);
}

int	ft_dectohex(unsigned long long dec, char s)
/* unsigned long long is for the number itself
** int for the number of output characters
** we dont have to handle the minuscase
** % rem X.yyy -> yyy times 16
*/
{
	int		rem;
	char	reversedigit[20];
	int		i;

	i = 0;
	if (dec == 0)
		return (write(1, "0", 1));
	while (dec > 0)
	{
		rem = dec % 16;
		if (rem < 10)
			reversedigit[i] = '0' + rem;
		else
		{
			if (s == 'x' || s == 'p')
				reversedigit[i] = 'a' + (rem - 10);
			if (s == 'X')
				reversedigit[i] = 'A' + (rem - 10);
		}
		dec = dec / 16;
		i++;
	}
	return (ft_end(&i, reversedigit));
}
