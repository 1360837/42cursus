/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:47:52 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/15 22:06:46 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	s_len;
	size_t	idx;

	s_len = ft_strlen(s);
	result = malloc(s_len + 1);
	if (!result)
		return (result);
	idx = 0;
	while (idx < s_len)
	{
		result[idx] = f(idx, s[idx]);
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
