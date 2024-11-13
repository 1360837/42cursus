/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:02:54 by jiwnam            #+#    #+#             */
/*   Updated: 2024/11/13 15:37:24 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	s_len;
	size_t	idx;

	idx = 0;
	s_len = ft_strlen(s);
	new = malloc(s_len + 1);
	if (new == NULL)
		return (new);
	while (*s)
		*(new + idx++) = *(s++);
	*(new + idx) = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	size;
	size_t	idx;

	size = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(size + 1);
	if (new == NULL)
		return (new);
	idx = 0;
	while (*s1)
		*(new + idx++) = *(s1++);
	while (*s2)
		*(new + idx++) = *(s2++);
	*(new + idx) = '\0';
	return (new);
}
