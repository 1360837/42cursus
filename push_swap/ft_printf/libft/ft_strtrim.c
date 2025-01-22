/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:53:07 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/15 16:46:23 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	trim_len(char const *s1, char const *set)
{
	size_t	len;
	size_t	idx;

	len = ft_strlen(s1);
	idx = 0;
	while (is_set(*((char *)s1 + idx), (char *)set))
	{
		len--;
		if (len == 0)
			return (len);
		idx++;
	}
	idx = ft_strlen(s1) - 1;
	while (is_set(*((char *)s1 + idx), (char *)set))
	{
		len--;
		if (len == 0)
			return (len);
		idx--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_s;
	size_t	size;
	size_t	start;
	size_t	idx;

	size = trim_len(s1, set);
	trimmed_s = malloc(size + 1);
	if (trimmed_s == NULL)
		return (trimmed_s);
	idx = 0;
	start = 0;
	while (is_set(*((char *)s1 + start), (char *)set))
		start++;
	while (idx < size)
	{
		*(trimmed_s + idx) = *((char *)s1 + start + idx);
		idx++;
	}
	*(trimmed_s + idx) = '\0';
	return (trimmed_s);
}
