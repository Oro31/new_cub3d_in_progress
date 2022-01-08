/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/08 13:11:28 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_pointer(t_all *vars)
{
	vars->spr.path = NULL;
	vars->spr.data = NULL;
	vars->map.box = NULL;
	vars->ray.xtex = NULL;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->wallface = NULL;
}

int	ft_init_before_parse(t_all *vars)
{
	ft_init_pointer(vars);
	vars->rsl.w = 0;
	vars->rsl.h = 0;
	vars->cam.pos.x = 0;
	vars->cam.pos.y = 0;
	vars->cam.dir = '\0';
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	if (!ft_malloc_dblchar(&(vars->map.box), 1))
		return (0);
	vars->map.box[0] = NULL;
	if (!ft_malloc_dblchar(&(vars->spr.path), 6))
		return (0);
	vars->spr.data = malloc(sizeof(t_data) * 5);
	if (!vars->spr.data)
		return (0);
	vars->spr.nbspr = 5;
	return (1);
}

int	ft_init_after_parse(t_all *vars)
{
	if (!ft_malloc_splint(&(vars->wallface), vars->rsl.w))
		return (0);
	if (!ft_malloc_splint(&(vars->ray.xtex), vars->rsl.w))
		return (0);
	return (1);
}