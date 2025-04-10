/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:41:08 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/20 18:43:27 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <ft_printf.h>
# include <libft.h>
# include <sys/types.h>

// client.c
void	send_message(pid_t s_pid, char *msg);
// server.c
void	recv_msg(int sig);

#endif
