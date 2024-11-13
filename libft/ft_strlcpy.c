/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:42:21 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/12 15:03:47 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	idx;

	idx = 0;
	src_len = ft_strlen(src);
	if (!size || !dst)
		return (src_len);
	while (idx + 1 < size && *(src + idx))
	{
		*(dst + idx) = *(src + idx);
		idx++;
	}
	*(dst + idx) = '\0';
	return (src_len);
}
