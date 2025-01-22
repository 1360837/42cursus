/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:26:31 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/15 00:44:22 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
