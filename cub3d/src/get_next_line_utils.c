/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:58:33 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/11 19:09:14 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"

int	is_endl(char *buf)
{
	int	i;

	i = 0;
	while (i < 4096 && buf[i] == '\0')
		i++;
	while (i < 4096 && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

static void	get_fill(char *buf, char *tmp, int i)
{
	int	j;

	j = 0;
	while (j < 4096 && buf[j] == '\0')
		j++;
	while (j < 4096 && buf[j] != '\n')
	{
		tmp[i] = buf[j];
		buf[j] = '\0';
		i++;
		j++;
	}
	if (j < 4096 && buf[j] == '\n')
		buf[j] = '\0';
	tmp[i] = '\0';
}

char	*get_realloc(char *buf, char **line)
{
	int		i;
	int		n;
	int		j;
	char	*tmp;

	i = 0;
	while (line[0][i])
		i++;
	j = 0;
	while (j < 4096 && buf[j] == '\0')
		j++;
	n = 0;
	while ((j + n) < 4096 && buf[j + n] != '\n')
		n++;
	if (!ft_malloc_splchar(&tmp, i + n + 1))
		return (NULL);
	j = -1;
	while (line[0][++j])
		tmp[j] = line[0][j];
	get_fill(buf, tmp, i);
	free(line[0]);
	*line = NULL;
	return (tmp);
}
