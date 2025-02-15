/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:50:27 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/15 18:38:41 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <ft_printf.h>
# include <libft.h>
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

// main.c

// so_long.c

// hook.c
int	key_hook(int key_code, t_mlx *ptr);
int	mouse_hook(int button, t_mlx *ptr);

// window.c
int	mlx_close(t_mlx *ptr);

#endif
