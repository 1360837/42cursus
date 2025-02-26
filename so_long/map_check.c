/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:22:42 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/26 17:55:54 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_line
{
	char				*map_line;
	struct s_map_node	*next;
}	t_line;

t_line	*read_map(int fd)
{
	char	*s;

	s = get_next_line(fd);
}

int	is_rectangle(char *input_line, int len)
{
	return ((int)ft_strlen(input_line) == len);
}

int	is_vaild_map(char *filename)
{

	return (1);
}

char **make_map(char *filename)
{
	int		row_cnt;
	int		col_cnt;
	char	**map;

}
