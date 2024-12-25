/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:54:09 by jiwnam            #+#    #+#             */
/*   Updated: 2024/12/25 23:11:25 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (buf)
	{
		if (ft_strchr(buf, '\n'))
			return (return_line("", &buf));
		line = ft_strjoin("", buf);
		if (!line)
			return (ft_free(NULL, &buf));
		free(buf);
	}
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ft_free(&line, &buf));
	return (make_line(line, &buf, fd));
}

char	*make_line(char *line, char **buf, int fd)
{
	int	read_len;

	read_len = 1;
	while (read_len > 0)
	{
		read_len = read(fd, *buf, BUFFER_SIZE);
		if (read_len < 0)
			return (ft_free(&line, buf));
		if (read_len == 0)
		{
			ft_free(NULL, buf);
			return (line);
		}
		*(*buf + read_len) = '\0';
		if (ft_strchr(*buf, '\n'))
			return (return_line(line, buf));
		if (!line)
			line = "";
		line = ft_strjoin(line, *buf);
		if (!line)
			return (ft_free(NULL, buf));
	}
	return (return_line(line, buf));
}

char	*return_line(char *line, char **buf)
{
	char	*new_buf;
	char	*buf_idx;

	buf_idx = ft_strchr(*buf, '\n') + 1;
	new_buf = ft_substr(buf_idx, 0, ft_strlen(buf_idx));
	if (!new_buf)
		return (ft_free(&line, buf));
	*(buf_idx) = '\0';
	if (!line)
		line = "";
	line = ft_strjoin(line, *buf);
	if (!line)
		return (ft_free(buf, &new_buf));
	free(*buf);
	if (ft_strlen(new_buf) < 1)
	{
		free(new_buf);
		new_buf = NULL;
	}
	*buf = new_buf;
	return (line);
}
