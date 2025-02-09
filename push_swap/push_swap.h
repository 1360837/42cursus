/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:26:17 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/09 23:51:28 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ft_printf.h>
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				top;
	unsigned int	*stack;
}	t_stack;

// push_swap.c
void			push_swap(t_stack *a, t_stack *b, int flag);
t_stack			*make_stack(char *av[], int size);
unsigned int	*make_arr(char *av[], int size);
void			stack_value(unsigned int *a, t_stack *s, t_stack *t, int size);
void			stack_idx_value(t_stack *a, t_stack *a_tmp);

// push_swap_utils.c
void			print_error(void **a);
int				is_num(char *str);
void			tmp_free(char **arr);
int				count_nums(char *str);
void			free_stack(t_stack *st1, t_stack *st2);

// radix_sort.c
void			radix_sort_atob_3(t_stack *a, t_stack *b, int digit, int flag);
void			radix_sort_btoa_3(t_stack *b, t_stack *a, int digit, int flag);
void			radix_sort_atob_4(t_stack *a, t_stack *b, int digit, int flag);
void			radix_sort_btoa_4(t_stack *b, t_stack *a, int digit, int flag);

// radix_sort_utils.c
unsigned int	calculate_data(t_stack *st, int digit, int radix);
int				check_4_radix_sort(int max_digit, int size);
int				find_digit(int size, int radix);

// mini_push_swap.c
void			mini_push_swap(t_stack *a, t_stack *b, char *av[], int size);
void			push_swap_2(t_stack *a);
void			push_swap_3(t_stack *a);
void			push_swap_4(t_stack *a, t_stack *b);
void			push_swap_5(t_stack *a, t_stack *b);

// swap.c
void			sa(t_stack *a, int print_flag);
void			sb(t_stack *b, int print_flag);
void			ss(t_stack *a, t_stack *b, int print_flag);

// push.c
void			pa(t_stack *a, t_stack *b, int print_flag);
void			pb(t_stack *a, t_stack *b, int print_flag);

// rotate.c
void			ra(t_stack *a, int print_flag);
void			rb(t_stack *b, int print_flag);
void			rr(t_stack *a, t_stack *b, int print_flag);

// reverse_rotate.c
void			rra(t_stack *a, int print_flag);
void			rrb(t_stack *b, int print_flag);
void			rrr(t_stack *a, t_stack *b, int print_flag);

// stack.c
t_stack			*init_stack(int size);
void			push(t_stack *st, int data);
int				pop(t_stack *st);
int				is_empty(t_stack *st);
int				is_sorted(t_stack *a);

#endif
