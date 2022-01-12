/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 08:09:32 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/12 17:51:30 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_redcross(t_all *vars)
{
	ft_free(vars);
	ft_close(vars);
	return (1);
}

int	ft_minimize(t_all *vars)
{
	ft_draw(vars);
	return (1);
}

void	ft_define_rslwin(t_all *vars)
{
	vars->win = mlx_new_window(vars->mlx, vars->rsl.w, vars->rsl.h, "cub");
}
