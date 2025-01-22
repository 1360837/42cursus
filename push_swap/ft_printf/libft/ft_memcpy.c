/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:41:46 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/14 22:50:16 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_buf;
	unsigned char	*src_buf;
	size_t			idx;

	if (!dest && !src)
		return (NULL);
	idx = 0;
	dest_buf = (unsigned char *)dest;
	src_buf = (unsigned char *)src;
	while (idx < n)
	{
		*(dest_buf + idx) = *(src_buf + idx);
		idx++;
	}
	return (dest);
}
