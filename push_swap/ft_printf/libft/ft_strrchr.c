/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:31:34 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/14 22:57:29 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_buf;
	size_t	idx;

	s_buf = (char *)s;
	idx = ft_strlen(s_buf);
	if ((unsigned char)c == 0)
		return (s_buf + idx);
	while (idx-- > 0)
	{
		if ((unsigned char)c == *(s_buf + idx))
			return (s_buf + idx);
	}
	return (NULL);
}
