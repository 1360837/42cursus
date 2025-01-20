/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:41:08 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/20 18:45:43 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <ft_printf.h>
# include <libft.h>
# include <sys/types.h>

// mini_client_bonus.c
void	send_message(pid_t s_pid, char *msg);
void	recv_message(int sig);
// server.c
void	recv_msg(int sig, siginfo_t *siginfo, void *context);

#endif
