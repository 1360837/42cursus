/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:38:48 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/16 14:37:18 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_word(char *s, char c)
{
	size_t	cnt;
	int		flag;

	cnt = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (cnt);
}

static char	*word_cpy(char	*start, char *end)
{
	char	*word;
	size_t	len;
	size_t	idx;

	len = (size_t)(end - start);
	idx = 0;
	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	while (idx < len)
	{
		*(word + idx) = *(start + idx);
		idx++;
	}
	*(word + idx) = '\0';
	return (word);
}

static char	**make_result(char *s, char c)
{
	char	**result;
	size_t	word_cnt;

	word_cnt = count_word(s, c);
	result = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (result == NULL)
		return (NULL);
	return (result);
}

char	**result_free(char **arr, size_t end_idx)
{
	size_t	idx;

	idx = 0;
	while (idx < end_idx)
		free(arr[idx++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*word_start;
	size_t	word_idx;

	result = make_result((char *)s, c);
	if (result == NULL)
		return (NULL);
	word_idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_start = (char *)s;
			while (*s && *s != c)
				s++;
			result[word_idx] = word_cpy(word_start, (char *)s);
			if (!result[word_idx++])
				return (result_free(result, word_idx));
		}
		else
			s++;
	}
	result[word_idx] = NULL;
	return (result);
}
