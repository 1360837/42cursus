/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:02:39 by jiwnam            #+#    #+#             */
/*   Updated: 2024/11/12 23:46:02 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fdlst	*fd_lst;
	t_fdlst		cur_fd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cur_fd = find_fdlst(&fd_lst, fd);
	
}
