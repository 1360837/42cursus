/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:10:57 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/19 18:52:10 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_num(char *str)
{
	int	str_len;

	if (ft_strncmp(str, "-2147483648", 11) == 0)
		return (1);
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	str_len = ft_strlen(str);
	if (str_len > 10 || str_len == 0)
		return (0);
	if (str_len == 10 && ft_strncmp(str, "2147483647", str_len) > 0)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
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
