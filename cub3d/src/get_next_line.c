/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 02:03:14 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/11 19:03:47 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"

static int	ft_rea_line(char *buf, char **line)
{
	*line = get_realloc(buf, line);
	if (!*line)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			rd_rtn_value;
	static char	buf[4096] = {0};

	if (fd < 0)
		return (-1);
	if (!ft_malloc_splchar(line, 1))
		return (-1);
	while (!(is_endl(buf)))
	{
		if (!ft_rea_line(buf, line))
			return (-1);
		rd_rtn_value = read(fd, buf, 4096);
		if (rd_rtn_value == -1)
			return (-1);
		else if (rd_rtn_value == 0)
			return (0);
	}
	if (is_endl(buf))
	{
		if (!ft_rea_line(buf, line))
			return (-1);
	}
	return (1);
}
