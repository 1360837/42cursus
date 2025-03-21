/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:49:40 by jiwnam            #+#    #+#             */
/*   Updated: 2025/03/08 22:59:06 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_mlx	ptr;
	int		fd;

	if (ac != 2)
		return (print_error("Usage: ./so_long <map file>"), 0);
	if (!is_valid_file(av[1]))
		return (print_error("Invalid map file: not .ber extension"), 0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (print_error("Open error"), 0);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 500, 500, av[0]);
	mlx_key_hook(ptr.win, key_hook, &ptr);
	mlx_hook(ptr.win, 17, 0, mlx_close, &ptr);
	mlx_mouse_hook(ptr.win, mouse_hook, &ptr);
	mlx_loop(ptr.mlx);
	// mlx 닫기
	close(fd);
}
