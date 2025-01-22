/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:40:30 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/16 14:09:01 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*cont_buf;
	t_list	*new;
	t_list	*newnode;

	new = NULL;
	while (lst)
	{
		cont_buf = f(lst->content);
		newnode = ft_lstnew(cont_buf);
		if (!newnode)
		{
			del(cont_buf);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, newnode);
		lst = lst->next;
	}
	newnode = NULL;
	return (new);
}
