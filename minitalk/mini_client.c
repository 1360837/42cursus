/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:36:47 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/17 23:48:33 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char *av[])
{
	pid_t	server_pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s <server PID> <string to send>", av[0]);
		exit(0);
	}
	server_pid = (pid_t)ft_atoi(av[1]);
	if (server_pid < 1)
	{
		ft_printf("Wrong server PID\n");
		exit(0);
	}
	signal(SIGUSR1, recv_message);
	signal(SIGUSR2, recv_message);
	send_message(server_pid, av[2]);
	return (0);
}

void	send_message(pid_t s_pid, char *msg)
{
	unsigned char	cur_c;
	int				bit;

	bit = 8;
	cur_c = 1;
	while (cur_c)
	{
		cur_c = *(msg++);
		while (bit > 0)
		{
			bit--;
			cur_c = cur_c >> 1;
			if (cur_c % 2 == 0)
				kill(s_pid, SIGUSR2);
			else
				kill(s_pid, SIGUSR1);
			pause();
		}
		write(1, " ", 1);
	}
}

void	recv_message(int sig)
{
	if (sig == SIGUSR1)
		write(1, "1", 1);
	else if (sig == SIGUSR2)
		write(1, "0", 1);
}
