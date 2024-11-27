/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:44:18 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/17 00:40:12 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cnt;
	size_t	idx;

	idx = 0;
	if (ft_strlen(little) == 0 || !little)
		return ((char *)big);
	while (*(big + idx) && idx < len)
	{
		cnt = 0;
		while (*(big + idx + cnt) == *(little + cnt) && *(little + cnt))
		{
			cnt++;
			if (idx + cnt >= len)
				break ;
		}
		if (cnt == ft_strlen(little))
			return ((char *)(big + idx));
		idx++;
	}
	return (NULL);
}
