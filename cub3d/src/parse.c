/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 08:06:15 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/12 19:14:45 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_line(int checkline, t_all *vars, char *line)
{
	int	i;

	i = 0;
	if (checkline == 2)
		i = ft_parse_tex(line, vars->spr.path);
	else if (checkline == 3)
	{
		if (line[0] == 'F')
			ft_rgb_fill(&vars->ground, line);
		else
			ft_rgb_fill(&vars->sky, line);
	}
	else if (checkline == 4)
		vars->map.box = ft_parse_map(line, vars->map.box);
	free(line);
}
