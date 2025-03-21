/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:04:06 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/12 15:16:33 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	dst_len;
	size_t	src_len;

	idx = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	while (idx + 1 < size - dst_len && *(src + idx))
	{
		*(dst + (dst_len + idx)) = *(src + idx);
		idx++;
	}
	*(dst + (dst_len + idx)) = '\0';
	return (dst_len + src_len);
}
