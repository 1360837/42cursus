/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:37:03 by jiwnam            #+#    #+#             */
/*   Updated: 2024/12/27 00:10:01 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <libft.h>

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
