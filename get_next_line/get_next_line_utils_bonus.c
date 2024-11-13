/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:17:30 by jiwnam            #+#    #+#             */
/*   Updated: 2024/11/12 22:45:15 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_fdlst	*find_fdlst(t_fdlst **lst, int fd)
{
	t_fdlst	*new;
	t_fdlst	*tmp;

	tmp = *lst;
	new = malloc(sizeof(t_fdlst));
	if (new == NULL)
		return (NULL);
	if (*lst)
	{
		while (tmp->link == NULL)
		{
			if (tmp->fd == fd)
			{
				free(new);
				return (*tmp);
			}
			tmp = tmp->link;
		}
		tmp->link = new;
	}
	else
		*lst = new;
	new->fd = fd;
	new->link = NULL;
	return (new);
}
