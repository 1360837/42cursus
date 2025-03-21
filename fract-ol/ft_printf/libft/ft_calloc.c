/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:51:05 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/15 00:34:42 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (size != 0 && nmemb > UINT_MAX / size)
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
		return (result);
	ft_bzero(result, size * nmemb);
	return (result);
}	
