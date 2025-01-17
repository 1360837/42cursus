/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:39:11 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/18 00:18:01 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &recv_msg;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("server pid : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

void	recv_msg(int sig, siginfo_t *siginfo, void *context)
{
	static unsigned char	recv_c;
	static int				bit_cnt;

	(void)context;
	recv_c <<= 1;
	recv_c |= (sig == SIGUSR1);
	bit_cnt++;
	if (bit_cnt == 8)
	{
		if (recv_c == 0)
			write(1, "\n", 1);
		else
			write(1, &recv_c, 1);
		bit_cnt = 0;
		recv_c = 0;
	}
	kill(siginfo->si_pid, sig);
}
