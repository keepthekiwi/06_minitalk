/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:06:09 by skillian          #+#    #+#             */
/*   Updated: 2021/12/12 18:49:54 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int base, unsigned int factor)
{
	unsigned int	i;
	int				j;

	if (factor == 0)
		return (1);
	i = 0;
	j = 1;
	while (i < factor)
	{
		j *= base;
		++i;
	}
	return (j);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%i\n", pid);
	signal(SIGUSR1, get_bit_by_bit);
	signal(SIGUSR2, get_bit_by_bit);
	while (1)
	{
		pause();
	}
}

void	get_bit_by_bit(int signal)
{
	static int				currentbit = 0;   //durfte ichd as so machen???
	static unsigned char	chr = 0;

	if (signal == SIGUSR1)
	{
		chr += ft_pow(2, currentbit);
	}
	currentbit++;
	if (currentbit == 8)
	{
		ft_putchar_fd(chr, 1);
		chr = 0;
		currentbit = 0;
	}
}
