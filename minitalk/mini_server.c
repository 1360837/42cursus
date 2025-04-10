/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:39:11 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/20 18:39:02 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	signal(SIGUSR1, recv_msg);
	signal(SIGUSR2, recv_msg);
	ft_printf("server pid : %d\n", getpid());
	while (1)
		pause();
	return (0);
}

void	recv_msg(int sig)
{
	static unsigned char	recv_c;
	static int				bit_cnt;

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
	else
		recv_c <<= 1;
}
