/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:08:07 by skillian          #+#    #+#             */
/*   Updated: 2021/12/12 18:34:14 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include "./libft/libft.h"
// ft_print function

int		ft_pow(int base, unsigned int factor);
void	signal_handler(int signal_no);
void	send_message_bitwise(int pid, char *message, size_t len_msg);
void	get_bit_by_bit(int bit);

#endif