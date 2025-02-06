/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:26:17 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/06 18:27:19 by jiwnam           ###   ########.fr       */
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

//push_swap.c
void			push_swap(t_stack *a, t_stack *b);
int				find_digit(int size, int radix);
unsigned int	*make_arr(char *av[], int size);
void			stack_value(unsigned int *arr, t_stack *st, int size);

//radix_sort.c
void			radix_sort_a_to_b_3(t_stack *a, t_stack *b, int digit);
void			radix_sort_b_to_a_3(t_stack *b, t_stack *a, int digit);
void			radix_sort_a_to_b_4(t_stack *a, t_stack *b, int digit);
void			radix_sort_b_to_a_4(t_stack *b, t_stack *a, int digit);

//push_swap_utils.c
void			print_error(void **a1, void **a2);
int				is_num(char *str);
void			tmp_free(char **arr);
int				count_nums(char *str);
void			free_stack(t_stack **st1, t_stack **st2);

//swap.c
void			sa(t_stack *a, int print_flag);
void			sb(t_stack *b, int print_flag);
void			ss(t_stack *a, t_stack *b, int print_flag);

//push.c
void			pa(t_stack *a, t_stack *b, int print_flag);
void			pb(t_stack *a, t_stack *b, int print_flag);

//rotate.c
void			ra(t_stack *a, int print_flag);
void			rb(t_stack *b, int print_flag);
void			rr(t_stack *a, t_stack *b, int print_flag);

//reverse_rotate.c
void			rra(t_stack *a, int print_flag);
void			rrb(t_stack *b, int print_flag);
void			rrr(t_stack *a, t_stack *b, int print_flag);

//stack.c
t_stack			*init_stack(int size);
void			push(t_stack *st, int data);
int				pop(t_stack *st);
int				is_empty(t_stack *st);
int				is_sorted(t_stack *a);

#endif
