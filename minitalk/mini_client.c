/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:36:47 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/15 18:00:38 by jiwnam           ###   ########.fr       */
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
	
