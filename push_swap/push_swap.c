/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:45 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/02 20:35:17 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	static t_stack	*a;
	static t_stack	*b;
	static int		cnt;
	static int		idx;
	int				*tmp_arr;

	if (ac == 1)
		return (0);
	while (*(av[idx]))
		cnt += count_nums(av[idx++]);
	tmp_arr = malloc(sizeof(int) * cnt);
	if (!tmp_arr)
	a = init_stack(cnt);
	if (!a)
		print_error((void **)&tmp_arr, NULL);
	// a에 값 넣어주기
	free(tmp_arr);
	b = init_stack(cnt);
	if (!b)
		print_error((void **)&a, NULL);

	push_swap(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && is_empty(b))
		return ;
	while (1)
	{
		if (is_empty(a) && is_sorted(b))
			break ;
		// a에서 제일 작은수를 찾아서 pb
	}
	while (!is_empty(b))
		pa(a, b);
	return ;
}

int	count_nums(char *str)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (*str)
	{
		if (!is_num(str))
			print_error(NULL, NULL);
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
