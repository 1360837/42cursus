/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:19:58 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/16 01:24:57 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	idx;
	char			*sub_s;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_s = malloc(len + 1);
	if (sub_s == NULL)
		return (NULL);
	idx = 0;
	while (idx < (unsigned int)len && *(s + start + idx))
	{
		*(sub_s + idx) = *(s + start + idx);
		idx++;
	}
	*(sub_s + idx) = '\0';
	return (sub_s);
}
