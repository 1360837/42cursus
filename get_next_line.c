/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:54:31 by jiwnam            #+#    #+#             */
/*   Updated: 2024/11/13 15:27:05 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_str(char **s1, char **s2, int flag, char *line)
{
	if (s1 != NULL && *s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 != NULL && *s2 != NULL)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (flag)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			read_cnt;
	static int	idx;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buf == NULL)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		read_cnt = read(fd, buf, BUFFER_SIZE);
		if (read_cnt <= 0)
		{
			idx = 0;
			return (free_str(&buf, NULL, 1, NULL));
		}
		buf[read_cnt] = '\0';
	}
	line = read_next_line(fd, &buf, &idx);
	if (line == NULL)
		return (free_str(&buf, NULL, 1, NULL));
	return (line);
}

char	*read_next_line(int fd, char **buf, int *idx)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*line;
	int		read_cnt;
	int		tmp_idx;

	line = NULL;
	tmp_idx = 0;
	while (*buf[*idx] != '\n')
	{
		if (*buf[*idx] == '\0')
		{
			read_cnt = read(fd, *buf, BUFFER_SIZE);
			*idx = 0;
			tmp[tmp_idx] = '\0';
			line = ft_strjoin(line, tmp);
			if (read_cnt <= 0)
				return (free_str(buf, NULL, read_cnt, line));
			(*buf)[read_cnt] = '\0';
			tmp_idx = 0;
		}
		tmp[tmp_idx++] = *buf[(*idx)++];
	}
	line = ft_strjoin(line, tmp);
	if (*(*buf + *idx) == '\0')
	{
		free_str(buf, NULL, 1, NULL);
		*idx = 0;
	}
	if (line == NULL)
		return (free_str(buf, NULL, 1, NULL));
	return (line);
}
