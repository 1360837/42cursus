/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:49:40 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/15 18:42:52 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx	ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 500, 500, "so_long");
	mlx_key_hook(ptr.win, key_hook, &ptr);
	mlx_hook(ptr.win, 17, 0, mlx_close, &ptr);
	mlx_mouse_hook(ptr.win, mouse_hook, &ptr);
	mlx_loop(ptr.mlx);
}
