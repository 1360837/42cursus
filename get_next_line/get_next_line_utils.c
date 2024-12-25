/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:06:17 by jiwnam            #+#    #+#             */
/*   Updated: 2024/12/25 23:13:28 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	size_t	idx;

	idx = 0;
	if (str == NULL)
		return (NULL);
	while (*(str + idx))
	{
		if (c == *(str + idx))
			return (str + idx);
		idx++;
	}
	if (c == 0)
		return (str + idx);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s1_tmp;
	char	*new;
	size_t	size;
	size_t	idx;

	size = ft_strlen(s1) + ft_strlen(s2);
	idx = 0;
	new = malloc(size + 1);
	s1_tmp = s1;
	if (!new)
		return (NULL);
	while (*s1)
		*(new + idx++) = *(s1++);
	while (*s2)
		*(new + idx++) = *(s2++);
	*(new + idx) = '\0';
	if (*s1_tmp)
		free(s1_tmp);
	return (new);
}

char	*ft_substr(char	*str, size_t start, size_t len)
{
	size_t	idx;
	char	*new;

	new = malloc(BUFFER_SIZE + 1);
	if (!new)
		return (NULL);
	idx = 0;
	while (idx < len && *(str + start + idx))
	{
		*(new + idx) = *(str + start + idx);
		idx++;
	}
	*(new + idx) = '\0';
	return (new);
}

char	*ft_free(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}
