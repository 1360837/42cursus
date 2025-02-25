/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:50:27 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/25 22:40:04 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <ft_printf.h>
# include <libft.h>
# include <get_next_line.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

# define ESC 27
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

// so_long.c

// so_long_utils.c
void	print_error(char *message);
int		is_valid_file(char *av);

// map_check.c
int		is_rectangle(char *input_line, int len);
int		is_valid_map(char *filename);
char	 **make_map(char *filename);

// hook.c
int		key_hook(int key_code, t_mlx *ptr);
int		mouse_hook(int button, t_mlx *ptr);

// window.c
int		mlx_close(t_mlx *ptr);

#endif
