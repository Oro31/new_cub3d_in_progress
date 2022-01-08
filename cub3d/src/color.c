/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:52:23 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/08 13:18:14 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_rgbtocolor(t_rgb *rgb)
{
	int		res;

	res = (rgb->r << 16 | rgb->g << 8 | rgb->b);
	return (res);
}

t_rgb	*ft_colortorgb(int color)
{
	t_rgb	*rgb;

	rgb = NULL;
	rgb->r = (color << 16) & 0xFF;
	rgb->g = (color << 8) & 0xFF;
	rgb->b = color & 0xFF;
	return (rgb);
}
