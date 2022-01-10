/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:26:42 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/10 16:08:31 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_replace_mapspace(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	ft_is_emptyline_inmap(int fd)
{
	char	*line;
	int		b;

	line = NULL;
	b = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_ismap_line(line))
			b = 1;
		if (!(ft_ismap_line(line)) && b == 1)
		{
			free(line);
			line = NULL;
			return (1);
		}
		free(line);
		line = NULL;
	}
	free(line);
	return (0);
}
