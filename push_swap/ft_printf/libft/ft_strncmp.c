/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:58:30 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/12 17:11:45 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_buf;
	unsigned char	*s2_buf;

	s1_buf = (unsigned char *)s1;
	s2_buf = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0 && (*s1_buf || *s2_buf))
	{
		if (*s1_buf != *s2_buf)
			return (*s1_buf - *s2_buf);
		s1_buf++;
		s2_buf++;
		n--;
	}
	return (0);
}
