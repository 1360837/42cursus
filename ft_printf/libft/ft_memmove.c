/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:47:05 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/15 17:04:37 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_buf;
	unsigned char	*dest_buf;
	size_t			idx;

	src_buf = (unsigned char *)src;
	dest_buf = (unsigned char *)dest;
	if (dest == src)
		return (dest_buf);
	if (dest_buf < src_buf)
	{
		idx = 0;
		while (idx < n)
		{
			*(dest_buf + idx) = *(src_buf + idx);
			idx++;
		}
	}
	else
	{
		while (n-- > 0)
			*(dest_buf + n) = *(src_buf + n);
	}
	return (dest);
}
