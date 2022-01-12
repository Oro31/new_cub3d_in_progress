/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:50:28 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/11 19:35:00 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_myxpm_pixelput(t_all *vars, int e, t_pos *pos)
{
	int	color;
	int	b;
	int	px;
	int	py;

	b = pos->y - e;
	px = vars->ray.xtex[pos->x];
	py = ft_get_pxy(b, vars->rsl.h - (2 * e));
	color = ft_get_xpm_pixel(&vars->spr.data[vars->wallface[pos->x]],
			px, py);
	return (color);
}

int	ft_get_pxy(int xy, int wh)
{
	double	pxy;

	pxy = (double)(xy / ((double)wh / 64));
	pxy = (int)pxy % 64;
	return (pxy);
}

int	ft_get_xpm_pixel(t_data *data, int x, int y)
{
	int	color;

	color = *((int *)data->addr + (x + y * 64));
	return (color);
}
