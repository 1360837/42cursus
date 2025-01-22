/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:00:44 by jiwnam            #+#    #+#             */
/*   Updated: 2024/12/27 00:39:53 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	av_p;
	int		cnt;

	cnt = 0;
	va_start(av_p, format);
	while (*format)
	{
		if (*format == '%')
			cnt += print_type(*(++format), av_p);
		else
			cnt += write(1, format, 1);
		format++;
	}
	va_end(av_p);
	return (cnt);
}

int	print_type(const char type, va_list av_p)
{
	int	cnt;

	cnt = -1;
	if (type == 'd' || type == 'i')
		cnt = print_num(va_arg(av_p, int));
	if (type == 'c')
	{
		cnt = 1;
		ft_putchar_fd(va_arg(av_p, int), 1);
	}
	if (type == 's')
		cnt = print_str(va_arg(av_p, char *));
	if (type == 'x')
		cnt = print_unum(va_arg(av_p, unsigned int), "0123456789abcdef");
	if (type == 'X')
		cnt = print_unum(va_arg(av_p, unsigned int), "0123456789ABCDEF");
	if (type == 'u')
		cnt = print_unum(va_arg(av_p, unsigned int), "0123456789");
	if (type == 'p')
		cnt = print_addr(va_arg(av_p, void *));
	if (type == '%')
		cnt = write(1, "%", 1);
	return (cnt);
}

int	print_str(char *str)
{
	int	cnt;

	cnt = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[cnt])
		write(1, &str[cnt++], 1);
	return (cnt);
}

int	print_addr(void	*addr)
{
	unsigned long	u_addr;
	char			buf[18];
	int				idx;

	idx = 17;
	ft_memset(buf, 0, 18);
	u_addr = (unsigned long)addr;
	if (!u_addr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	while (u_addr > 0)
	{
		buf[idx--] = "0123456789abcdef"[u_addr % 16];
		u_addr /= 16;
	}
	buf[idx--] = 'x';
	buf[idx] = '0';
	write(1, &buf[idx], 18 - idx);
	return (18 - idx);
}
