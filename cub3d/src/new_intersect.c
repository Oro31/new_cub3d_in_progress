/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:52:23 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/12 15:24:14 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_define_ray(t_ray *ray, char c)
{
	while (ray->a < 0)
		ray->a += 2 * M_PI;
	while (ray->a > 2 * M_PI)
		ray->a -= 2 * M_PI;
	if (ray->a < M_PI && ray->a > 0)
		ray->sy = -1;
	else
		ray->sy = 1;
	if (ray->a > M_PI / 2 && ray->a < 3 * M_PI / 2)
		ray->sx = -1;
	else
		ray->sx = 1;
	if ((ray->f < M_PI / 2 + APPROXI && ray->f > M_PI / 2 - APPROXI)
		|| (ray->f < 3 * M_PI / 2 + APPROXI
			&& ray->f > 3 * M_PI / 2 - APPROXI))
		ray->t = tan(ray->a);
	else
		ray->t = 1 / tan(ray->a);
	if (c == 'v')
		ray->t = 1 / ray->t;
	if (ray->t < 0)
		ray->t *= -1;
}

double	ft_new_hor_inte(t_all *vars, t_ray *ray, int i)
{
	double	tmp;

	ft_define_ray(ray, 'h');
	ray->y = (double)((vars->cam.pos.y + (1 + ray->sy) / 2) * 64);
	ray->x = (double)(vars->cam.pos.x * 64) + 32 + ray->sx * 32 * ray->t;
	while (ft_check_wall(vars, ray, 'h', i))
	{
		ray->x += ray->sx * 64 * ray->t;
		ray->y += ray->sy * 64;
	}
	ray->xtex[i] = (int)ray->x % 64;
	tmp = pow(((double)vars->cam.pos.y * 64) + 32 - ray->y, 2)
		+ pow(((double)vars->cam.pos.x * 64) + 32 - ray->x, 2);
	return (sqrt(tmp));
}

double	ft_new_ver_inte(t_all *vars, t_ray *ray, int i)
{
	double	tmp;

	ft_define_ray(ray, 'v');
	ray->x = (double)((vars->cam.pos.x + (1 + ray->sx) / 2) * 64);
	ray->y = (double)(vars->cam.pos.y * 64) + 32 + ray->sy * 32 * ray->t;
	while (ft_check_wall(vars, ray, 'v', i))
	{
		ray->y += ray->sy * 64 * ray->t;
		ray->x += ray->sx * 64;
	}
	ray->xtex[i] = (int)ray->y % 64;
	tmp = pow(((double)vars->cam.pos.y * 64) + 32 - ray->y, 2)
		+ pow(((double)vars->cam.pos.x * 64) + 32 - ray->x, 2);
	return (sqrt(tmp));
}
