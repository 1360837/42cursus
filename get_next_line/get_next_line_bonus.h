/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:03:21 by jiwnam            #+#    #+#             */
/*   Updated: 2024/11/12 22:36:19 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

typedef struct s_fdlst
{
	struct s_fdlst	*link;
	int				fd;
	char			*buf;
	int				idx;
}	t_fdlst;

//get_next_line_bonus.c
char	*get_next_line(int fd);

//get_next_line_utils_bonus.c
t_fdlst	*find_fdlst(t_fdlst **lst, int fd);

#endif
