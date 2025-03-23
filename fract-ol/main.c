/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:47:23 by jiwnam            #+#    #+#             */
/*   Updated: 2025/03/21 23:56:33 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_fractol_list(char **list, int size)
{
	int	idx;

	ft_printf("%s\n", "* Available fractals *");
	idx = 0;
	while (idx < size)
		ft_printf(" - %s\n", list[idx++]);
}

int	main(int ac, char *av[])
{
	//const char	*fractal_list[2] = {"mandelbrot", "Julia"};

	if (ac != 2)
	{
		ft_printf("%s\n", "Usage: ./fractol <fractal name>");
		print_fractol_list((char *[2]){"mandelbrot", "Julia"}, 2);
		exit(1);
	}
	ft_printf("%s", av[0]);
	// mlx 열기
	// fractal 이름하고 비교해서 일치하는 fractal 함수로 들어가기
	// mlx 닫기
}
