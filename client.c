/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:48:27 by skillian          #+#    #+#             */
/*   Updated: 2021/12/14 17:52:23 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*	kill() to send a signal
	signal() to receive a signal */

int	main(int argc, char *argv[])
{
	int		pid_server;
	char	*message;

	if (argc != 3)
	{
		return (ft_printf("Please use format: \
		./client [PID] [your_message_in_quotes]"));
		exit(0);
	}
	message = argv[2];
	pid_server = ft_atoi(argv[1]);
	send_message_bitwise(pid_server, message, ft_strlen(message));
	send_message_bitwise(pid_server, "\n", 1);
	return (0);
}

void	send_message_bitwise(int pid, char *message, size_t len_msg)
{
	size_t	i;
	int		bitshift;

	i = 0;
	if (!message)
		exit (0);
	while (i <= len_msg)
	{
		bitshift = 0;
		while (bitshift < 8)
		{
			if ((message[i] >> bitshift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bitshift++;
			usleep(100);
		}
		i++;
	}
}
