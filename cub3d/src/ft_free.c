/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/12 19:18:27 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_sprites(t_all *vars)
{
	int	i;

	if (vars->spr.path)
	{
		i = -1;
		while (++i < vars->spr.nbspr)
		{
			if (vars->spr.data[i].img)
				mlx_destroy_image(vars->mlx, vars->spr.data[i].img);
			if (vars->spr.path[i])
				free(vars->spr.path[i]);
		}
		if (vars->spr.data)
			free(vars->spr.data);
		free(vars->spr.path);
	}
}

void	ft_free_map(t_map *map)
{
	int	i;

	if (map->box)
	{
		i = -1;
		while (map->box[++i])
			free(map->box[i]);
		free(map->box);
	}
}

int	ft_free(t_all *vars)
{
	ft_free_sprites(vars);
	ft_free_map(&vars->map);
	if (vars->wallface)
		free(vars->wallface);
	if (vars->ray.xtex)
		free(vars->ray.xtex);
	return (0);
}
