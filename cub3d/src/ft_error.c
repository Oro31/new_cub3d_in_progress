/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:29:35 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/13 19:15:08 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error_msg(int err_code)
{
	write(1, "Error\n", 6);
	if (err_code == 1)
		write(1, "wrong argument\n", 15);
	else if (err_code == 2)
		write(1, "open failed\n", 12);
	else if (err_code == 3)
		write(1, "wrong map\n", 10);
	else if (err_code == 4)
		write(1, "wrong textures\n", 15);
	else if (err_code == 5)
		write(1, "wrong rgb\n", 10);
	return (0);
}
