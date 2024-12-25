/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:07:06 by jiwnam            #+#    #+#             */
/*   Updated: 2024/12/25 23:28:34 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//get_next_line.c
char	*get_next_line(int fd);
char	*make_line(char *line, char **buf, int fd);
char	*return_line(char *line, char **buf);

//get_next_line_utils.c
char	*gnl_strchr(char *str, int c);
size_t	gnl_strlen(char *str);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char	*str, size_t start, size_t len);
char	*gnl_free(char **s1, char **s2);

#endif
