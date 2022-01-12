/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:26:42 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/11 18:35:33 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_ismap_member(char c)
{
	if ((c >= '0' && c <= '2') || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	ft_len_mpline(char *line)
{
	int		i;

	i = 0;
	while (ft_ismap_member(line[i]) || line[i] == ' ')
		i++;
	return (i);
}

char	*ft_linemap_realloc(char **map, int i)
{
	int		j;
	int		len;
	int		maxlen;
	char	*tmp;

	maxlen = ft_lenmax_mpline(map);
	len = ft_len_mpline(map[i]);
	if (!ft_malloc_splchar(&tmp, maxlen + 1))
		return (NULL);
	j = -1;
	while (++j < len)
		tmp[j] = map[i][j];
	while (j < maxlen)
	{
		tmp[j] = ' ';
		j++;
	}
	return (tmp);
}

char	*ft_linemap_fill(char *line, int maxlen)
{
	int		i;
	int		len;
	int		mal_len;
	char	*tmp;

	len = ft_len_mpline(line);
	if (maxlen > len)
		mal_len = maxlen;
	else
		mal_len = len;
	if (!ft_malloc_splchar(&tmp, mal_len + 1))
		return (0);
	i = -1;
	while (++i < len)
		tmp[i] = line[i];
	while (i < maxlen)
	{
		tmp[i] = ' ';
		i++;
	}
	return (tmp);
}

char	**ft_parse_map(char *line, char **map)
{
	int		i;
	int		fstdm;
	char	**tmp;

	i = 0;
	if (map)
		while (map[i])
			i++;
	fstdm = i;
	if (!ft_malloc_dblchar(&tmp, fstdm + 2))
		return (NULL);
	i = -1;
	while (++i < fstdm)
		tmp[i] = ft_linemap_realloc(map, i);
	tmp[fstdm] = ft_linemap_fill(line, ft_lenmax_mpline(map));
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	return (tmp);
}
