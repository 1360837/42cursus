/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:36:47 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/20 18:39:45 by jiwnam           ###   ########.fr       */
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
	send_message(server_pid, av[2]);
	return (0);
}

void	send_message(pid_t s_pid, char *msg)
{
	unsigned char	cur_c;
	int				bit;
	int				idx;

	idx = 0;
	while (1)
	{
		bit = 8;
		while (bit > 0)
		{
			bit--;
			cur_c = msg[idx] >> bit;
			if (cur_c % 2 == 0)
				kill(s_pid, SIGUSR2);
			else
				kill(s_pid, SIGUSR1);
			usleep(1000);
		}
		if (!msg[idx])
			break ;
		idx++;
	}
}
