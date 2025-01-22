/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:22:44 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/14 22:57:19 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_buf;
	size_t	idx;

	idx = 0;
	s_buf = (char *)s;
	while (*(s + idx))
	{
		if ((unsigned char)c == *(s_buf + idx))
			return (s_buf + idx);
		idx++;
	}	
	if ((unsigned char)c == 0)
		return (s_buf + idx);
	return (NULL);
}
