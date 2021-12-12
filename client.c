/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:48:27 by skillian          #+#    #+#             */
/*   Updated: 2021/12/12 18:33:33 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int		pid_server;								
	char	*message;

	if (argc != 3)
	{
		return (printf("Please use format: ./client [PID] [your_message_in_quotes]"));	//<<<<<<ft_printf
		exit(0);																		//exit failure
	}
	message = argv[2];	
	pid_server = ft_atoi(argv[1]);
	send_message_bitwise(pid_server, message, ft_strlen(message));
	send_message_bitwise(pid_server, "\n", 1);
	return(0);																			//sucess
}




void send_message_bitwise(int pid, char *message, size_t len_msg)
{
	size_t i;
	int bitshift;

	i = 0;

	if(!message)
		exit (0);																		//failure // kann ich auch in oberfunktion reinmachen

	while(i <= len_msg)
	{
		bitshift = 0;
		while (bitshift < 8)
		{
			if((message[i] >> bitshift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bitshift++;
			usleep(100);
		}
		i++;
	}
}
