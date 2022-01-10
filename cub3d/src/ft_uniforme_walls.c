/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uniforme_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/10 14:06:53 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_unif_walls(double *wall, int i)
{
	double	m;
	int		j;

	while (i > 0)
	{
		i--;
		m = 0;
		j = 0;
		while (i - j + 1 < 640 && i - j > 0
			&& wall[i - j] < (wall[i - j + 1] + 0.01)
			&& wall[i - j] > (wall[i - j + 1] - 0.01))
		{
			m = m + wall[i - j];
			j++;
		}
		m = m / j;
		while (i < 639 && i > 0 && wall[i] < (wall[i + 1] + 0.01)
			&& wall[i] > (wall[i + 1] - 0.01))
		{
			wall[i] = m;
			i--;
		}
		i--;
	}
}
