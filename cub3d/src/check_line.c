/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 08:06:15 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/12 17:15:49 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_istex_line(char *line)
{
	if ((line[0] == 'N' || line[0] == 'S') && line[1] == 'O'
		&& line[2] == ' ')
		return (1);
	else if (((line[0] == 'E' && line[1] == 'A')
			|| (line[0] == 'W' && line[1] == 'E')) && line[2] == ' ')
		return (1);
	else if (line[0] == 'S' && line[1] == ' ')
		return (1);
	else
		return (0);
}

int	ft_isrgb_line(char *line)
{
	if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
		return (1);
	return (0);
}

int	ft_ismap_line(char *line)
{
	int		i;
	int		b;
	char	c;

	b = 0;
	i = 0;
	while (line[i])
	{
		c = line[i];
		if (!(ft_ismap_member(c) || c == ' '))
			return (0);
		if (c >= '0' && c <= '2')
			b = 1;
		i++;
	}
	if (b == 1)
		return (1);
	return (0);
}

int	ft_check_line(char *line)
{
	if (ft_istex_line(line))
		return (2);
	else if (ft_isrgb_line(line))
		return (3);
	else if (ft_ismap_line(line))
		return (4);
	else
		return (0);
}
