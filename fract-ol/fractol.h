/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:50:35 by jiwnam            #+#    #+#             */
/*   Updated: 2025/03/22 01:22:43 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <ft_printf.h>
# include <libft.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_ptr;

}	t_fractal;

# define ESC 27
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

#endif
