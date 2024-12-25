/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:54:09 by jiwnam            #+#    #+#             */
/*   Updated: 2024/12/25 23:43:23 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (buf[fd])
	{
		if (gnl_strchr(buf[fd], '\n'))
			return (return_line("", &buf[fd]));
		line = gnl_strjoin("", buf[fd]);
		if (!line)
			return (gnl_free(NULL, &buf[fd]));
		free(buf[fd]);
	}
	buf[fd] = malloc(BUFFER_SIZE + 1);
	if (!buf[fd])
		return (gnl_free(&line, &buf[fd]));
	return (make_line(line, &buf[fd], fd));
}

char	*make_line(char *line, char **buf, int fd)
{
	int	read_len;

	read_len = 1;
	while (read_len > 0)
	{
		read_len = read(fd, *buf, BUFFER_SIZE);
		if (read_len < 0)
			return (gnl_free(&line, buf));
		if (read_len == 0)
		{
			gnl_free(NULL, buf);
			return (line);
		}
		*(*buf + read_len) = '\0';
		if (gnl_strchr(*buf, '\n'))
			return (return_line(line, buf));
		if (!line)
			line = "";
		line = gnl_strjoin(line, *buf);
		if (!line)
			return (gnl_free(NULL, buf));
	}
	return (return_line(line, buf));
}

char	*return_line(char *line, char **buf)
{
	char	*new_buf;
	char	*buf_idx;

	buf_idx = gnl_strchr(*buf, '\n') + 1;
	new_buf = gnl_substr(buf_idx, 0, gnl_strlen(buf_idx));
	if (!new_buf)
		return (gnl_free(&line, buf));
	*(buf_idx) = '\0';
	if (!line)
		line = "";
	line = gnl_strjoin(line, *buf);
	if (!line)
		return (gnl_free(buf, &new_buf));
	free(*buf);
	if (gnl_strlen(new_buf) < 1)
	{
		free(new_buf);
		new_buf = NULL;
	}
	*buf = new_buf;
	return (line);
}
