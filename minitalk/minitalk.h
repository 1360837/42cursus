/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:41:08 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/12 18:30:31 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf.h"

// client.c

// server.c

//ft_printf.c
int		ft_printf(const char *av, ...);
int		print_type(const char type, va_list av_p);
int		print_str(char *str);
int		print_addr(void *addr);

//ft_printf_unum.c
int		print_unum(unsigned int unum, char *base);
void	ft_putnbr_base(unsigned int n, char *base, int base_digit);
int		count_digit_base(unsigned int n, int base);
int		print_num(int n);
int		count_digit(int n);

#endif
