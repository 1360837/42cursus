/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:54:31 by jiwnam            #+#    #+#             */
/*   Updated: 2024/11/12 19:37:13 by jiwnam           ###   ########.fr       */
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
	char	tmp[2];
	char	*line;
	int		read_cnt;

	line = NULL;
	tmp[0] = *(*buf + (*idx)++);
	tmp[1] = '\0';
	while (tmp[0] != '\n')
	{
		if (tmp[0] == '\0')
		{
			read_cnt = read(fd, *buf, BUFFER_SIZE);
			*idx = 0;
			if (read_cnt <= 0)
			{	
				line = ft_strjoin(line, tmp);
				return (free_str(buf, NULL, read_cnt, line));
			}
			(*buf)[read_cnt] = '\0';
		}
		line = ft_strjoin(line, tmp);
		if (line == NULL)
			return (free_str(buf, NULL, 1, NULL));
		tmp[0] = *(*buf + (*idx)++);
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
