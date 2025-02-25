/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:38:35 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/19 22:55:47 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void **a)
{
	if (a && *a)
	{
		free(*a);
		*a = NULL;
	}
	write(2, "Error\n", 6);
	exit(0);
}

int	is_num(char *str)
{
	// int	str_len;
	// int	sign;

	// sign = 1;
	// if (*str == '-')
	// 	sign = -1;
	// if (*str == '+' || *str == '-')
	// 	str++;
	// while (*str == '0' && *(str + 1) == '0')
	// 	str++;
	// str_len = ft_strlen(str);
	// if (str_len > 10)
	// 	return (0);
	// if (str_len == 10 && ((sign == 1 && ft_strncmp(str, "2147483647", str_len) > 0) || (sign == -1 && ft_strncmp(str, "2147483648", str_len) > 0)))
	// 	return (0);
	// while (*str)
	// {
	// 	if (*str < '0' || *str > '9')
	// 		return (0);
	// 	str++;
	// }
	// return (1);
	int            i;
    int            minus;
    int            zero_count;
    long long    num;

    minus = 0;
    if (str[0] == '-')
        minus++;
    if (str[minus] == '\0' || str[minus] == ' ')
        return (0);
    i = 0;
    zero_count = 0;
    while (str[i + minus + zero_count] == '0')
        zero_count++;
    num = 0;
    while (str[i + minus])
    {
        num = (num * 10) + (str[i + minus] - '0');
        if (num - minus > 2147483647 || i - zero_count > 10)
            return (0);
        else if ('0' > str[i + minus] || str[i + minus] > '9')
            return (0);
        i++;
    }
    return (1);
}

void	tmp_free(char **arr)
{
	size_t	idx;

	if (!arr)
		return ;
	idx = 0;
	while (arr[idx])
		free(arr[idx++]);
	free(arr);
}

int	count_nums(char *str)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (*str)
	{
		if (*str != ' ' && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (*str == ' ')
			flag = 0;
		str++;
	}
	return (cnt);
}

void	free_stack(t_stack *st1, t_stack *st2)
{
	if (st1)
	{
		if (st1->stack)
			free(st1->stack);
		free(st1);
	}
	if (st2)
	{
		if (st2->stack)
			free(st2->stack);
		free(st2);
	}
}
