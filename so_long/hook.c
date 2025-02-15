/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:53:56 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/15 18:41:09 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int key_code, t_mlx *ptr)
{
	ft_printf("%d\n", (char)key_code);
	if ((char)key_code == ESC)
		return (mlx_close(ptr));


	return (0);
}

int	mouse_hook(int button, t_mlx *ptr)
{
	ft_printf("%d\n", (char)button);
	ft_printf("%p\n", ptr);
	return (0);
}
