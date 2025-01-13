/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:39:11 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/12 18:26:26 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	int				byte_num;
	unsigned int	c;
	pid_t			serv_pid;

	serv_pid = getpid();
	ft_printf("server pid : %d",serv_pid);

}	


