/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:29:35 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/12 19:45:31 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error_msg(int err_code)
{
	write(1, "Error\n", 6);
	if (err_code == 1)
		write(1, "wrong argument\n");
	else if (err_code == 2)
		write(1, "open failed\n");
	return (0);
}
