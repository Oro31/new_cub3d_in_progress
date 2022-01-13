/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:18:59 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/13 20:44:36 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_skip_space(char *line, int i, int n)
{
	while (n == 0 && line[i] == ' ')
		i++;
	while (n == 1 && ft_isdigit(line[i]))
		i++;
	return (i);
}

static int	ft_is_rgb_line_member(char *line)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (line[i])
	{
		i = ft_skip_space(line, i, 0);
		if (n % 2 == 0 && ft_isdigit(line[i]))
			n++;
		else if (n % 2 == 1 && line[i] == ',')
			n++;
		else if (line[i] != ' ' && line[i] != '\0')
			return (0);
		if (n % 2 == 1)
			i = ft_skip_space(line, i, 1);
		else if (line[i] != '\0')
			i++;
	}
	if (n > 5)
		return (0);
	return (1);
}

static void	ft_is_error_rgb_line(t_rgb *rgb, char *line)
{
	int	i;

	rgb->error = 0;
	i = 0;
	while (line[++i])
	   if (line[i] != ' ' && line[i] != ','  && !ft_isdigit(line[i]))
		   rgb->error = 1;
	if (!rgb->error && !ft_is_rgb_line_member(line))
		rgb->error = 1;
}

static void	ft_init_rgb(t_rgb *rgb, int *ret, int *i)
{
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
	rgb->error = 0;
	*ret = 0;
	*i = 0;
}

void	ft_rgb_fill(t_rgb *rgb, char *line)
{
	int		i;
	int		ret;
	uint8_t	tmp;

	ft_init_rgb(rgb, &ret, &i);
	ft_is_error_rgb_line(rgb, line);
	while (ret == 0 && line[i])
	{
		while (line[i] && !(ft_isdigit(line[i])))
			i++;
		tmp = 0;
		while (ft_isdigit(line[i]))
		{
			tmp = tmp * 10 + (line[i] - 48);
			i++;
		}
		if (rgb->r != 0 && rgb->g != 0 && rgb->b == 0)
			rgb->b = tmp;
		else if (rgb->r != 0 && rgb->g == 0 && rgb->b == 0)
			rgb->g = tmp;
		else if (rgb->r == 0 && rgb->g == 0 && rgb->b == 0)
			rgb->r = tmp;
		else
			ret = 0;
	}
}
