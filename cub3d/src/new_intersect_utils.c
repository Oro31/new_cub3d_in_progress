/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_intersect_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:52:23 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/12 15:26:49 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_xnew_check_maplimites(t_all *vars, int *x, int *res)
{
	if (*x >= ft_lenmax_mpline(vars->map.box))
	{
		*x = ft_lenmax_mpline(vars->map.box) - 1;
		*res = 2;
	}
	else if (*x < 0)
	{
		*x = 0;
		*res = 2;
	}
}

int	ft_new_check_maplimites(t_all *vars, int *x, int *y)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (vars->map.box[i])
		i++;
	if (*y >= i)
	{
		*y = i - 1;
		res = 1;
	}
	else if (*y < 0)
	{
		*y = 0;
		res = 1;
	}
	ft_xnew_check_maplimites(vars, x, &res);
	return (res);
}

int	ft_check_wall(t_all *vars, t_ray *ray, char c, int i)
{
	int	x;
	int	y;

	y = (int)(ray->y / 64);
	x = (int)(ray->x / 64);
	if (c == 'h' && (ray->a < M_PI && ray->a > 0))
		y -= 1;
	else if (c != 'h' && (ray->a < 3 * M_PI / 2 && ray->a > M_PI / 2))
		x -= 1;
	if (ft_new_check_maplimites(vars, &x, &y) != 0)
	{
		if (c == 'h')
			ray->xtex[i] = (int)ray->x % 64;
		else if (c == 'v')
			ray->xtex[i] = (int)ray->y % 64;
		if (ft_new_check_maplimites(vars, &x, &y) == 1)
			ray->y = (double)(y * 64);
		if (ft_new_check_maplimites(vars, &x, &y) == 2)
			ray->x = (double)(x * 64);
	}
	if (vars->map.box[y][x] == '1' || vars->map.box[y][x] == '2')
		return (0);
	return (1);
}
