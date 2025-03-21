/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:12:14 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/16 16:18:35 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_buf;
	size_t			idx;

	idx = 0;
	s_buf = (unsigned char *)s;
	while (idx < n)
	{
		if (*(s_buf + idx) == (unsigned char)c)
			return (s_buf + idx);
		idx++;
	}
	return (NULL);
}
