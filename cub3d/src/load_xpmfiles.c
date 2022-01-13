/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpmfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/13 17:08:49 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_fill_sprites(t_all *vars)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	while (i < vars->spr.nbspr)
	{
		if (!vars->spr.path[i])
			return (ft_error_msg(4));
		vars->spr.data[i].img = mlx_xpm_file_to_image(vars->mlx,
				vars->spr.path[i], &w, &h);
		if (!vars->spr.data[i].img)
			return (ft_error_msg(4));
		vars->spr.data[i].addr = mlx_get_data_addr(
				vars->spr.data[i].img, &vars->spr.data[i].bpp,
				&vars->spr.data[i].ll, &vars->spr.data[i].e);
		i++;
	}
	return (1);
}
