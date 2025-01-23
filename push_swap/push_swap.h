/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:26:17 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/23 19:25:04 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <ft_printf.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//push_swap.c
void	print_error(void);
void	init_stack(int **a, int **b, int size, char *arr[]);
void	ft_free(void **a1, void **a2);

//swap.c
void	sa(int **a); void  sb(int **b);
void	ss(int **a, int **b);

#endif
