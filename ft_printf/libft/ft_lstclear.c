/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:23:42 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/16 00:34:29 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_buf;

	while (*lst)
	{
		del((*lst)->content);
		lst_buf = (*lst)->next;
		(*lst)->next = NULL;
		free(*lst);
		*lst = lst_buf;
	}
}
