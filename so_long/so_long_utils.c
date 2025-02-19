/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:14:26 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/19 23:22:42 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_file(char *av)
{
	int	av_len;

	av_len = ft_strlen(av);
	if (ft_strncmp(av + av_len - 4, ".ber", 4))
		return (0);
	return (1);
}

int	is_vaild_map(char *filename)
{
	return (1);
}

void	print_error(char *message)
{
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
}
