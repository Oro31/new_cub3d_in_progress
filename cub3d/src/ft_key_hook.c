/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:52:23 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/11 18:43:54 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_close(t_all *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	ft_turn(t_all *vars, char c)
{
	float	fov;
	float	tmp;

	fov = ft_dir_to_fov(vars->cam.dir);
	if (c == 'l')
		tmp = fov + M_PI / 2;
	else
		tmp = fov - M_PI / 2;
	while (tmp > 2 * M_PI)
		tmp -= 2 * M_PI;
	while (tmp < 0)
		tmp += 2 * M_PI;
	vars->cam.dir = ft_fov_to_dir(tmp);
}

void	ft_moove(t_all *vars, char c)
{
	vars->map.box[vars->cam.pos.y][vars->cam.pos.x] = '0';
	if (c == 'w')
		ft_avancer(vars);
	else if (c == 's')
		ft_reculer(vars);
	else if (c == 'a')
		ft_lateral_gauche(vars);
	else if (c == 'd')
		ft_lateral_droite(vars);
	vars->map.box[vars->cam.pos.y][vars->cam.pos.x] = vars->cam.dir;
}

int	ft_moove_kyhk(int keycode, t_all *vars)
{
	if (keycode == 65307)
	{
		ft_free(vars);
		ft_close(vars);
	}
	else if (keycode == 65361)
		ft_turn(vars, 'l');
	else if (keycode == 65363)
		ft_turn(vars, 'r');
	else if (keycode == 119)
		ft_moove(vars, 'w');
	else if (keycode == 115)
		ft_moove(vars, 's');
	else if (keycode == 97)
		ft_moove(vars, 'a');
	else if (keycode == 100)
		ft_moove(vars, 'd');
	ft_draw(vars);
	return (1);
}
