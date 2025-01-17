/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:39:11 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/17 21:56:47 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	int					byte_num;
	unsigned int		c;
	struct sigaction	sa;

	sa.sa_sigaction = &recv_msg;
	sa.sa_flags = SA_SIGINFO;
	sigempty(&sa.sa_mask);
	ft_printf("server pid : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL); //error 처리 할까 말까
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

void	recv_msg(int signal)
{
	

}
