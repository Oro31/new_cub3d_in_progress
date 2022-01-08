/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/07 15:14:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel_on_img(t_data *img, int color, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_get_visual(t_all *vars)
{
	double	*wall;
	t_pos	pos;
	int		e;
	int		color;

	if (!(wall = malloc(sizeof(double) * vars->rsl.w)))
		return (0);
	ft_find_walls(vars, wall);
	pos.x = 0;
	while (pos.x < vars->rsl.w)
	{
		pos.y = -1;
		e = (vars->rsl.h - (int)(64 * 500 / wall[pos.x])) / 2;
		while (++pos.y < e)
			ft_put_pixel_on_img(&vars->img, vars->sky.color,
				       	pos.x, pos.y);
		while (++pos.y < (vars->rsl.h - e))
		{
			color = ft_myxpm_pixelput(vars, e, &pos);
			ft_put_pixel_on_img(&vars->img, color, pos.x, pos.y);
		}
		while (++pos.y < vars->rsl.h)
			ft_put_pixel_on_img(&vars->img, vars->ground.color,
					pos.x, pos.y);
		pos.x++;
	}
	free(wall);
	return (1);
}

int	ft_draw(t_all *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, vars->rsl.w, vars->rsl.h);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, 
			&vars->img.ll, &vars->img.e);
	if (ft_get_visual(vars) == 0)
		return (0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (1);
}
