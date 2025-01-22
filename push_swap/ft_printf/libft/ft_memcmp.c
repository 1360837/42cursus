/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:32:31 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/12 17:42:05 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_buf;
	unsigned char	*s2_buf;
	size_t			idx;

	if (n == 0)
		return (0);
	idx = 0;
	s1_buf = (unsigned char *)s1;
	s2_buf = (unsigned char *)s2;
	while (idx < n)
	{
		if (*(s1_buf + idx) != *(s2_buf + idx))
			return (*(s1_buf + idx) - *(s2_buf + idx));
		idx++;
	}
	return (0);
}
