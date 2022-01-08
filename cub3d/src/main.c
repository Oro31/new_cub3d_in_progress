/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/08 17:09:31 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_last_check(t_all *vars)
{
	if (!(ft_ismap_walled(vars->map.box)))
	{
		printf("map is not walled ?!!!! \n");
		return (ft_free(vars));
	}
	ft_replace_mapspace(vars->map.box);
	if (!(ft_init_after_parse(vars)))
	{
		if (vars->wallface != NULL)
			free(vars->wallface);
		return (ft_free(vars));
	}
	return (1);
}

static int	ft_init_start(t_all *vars)
{
	int		fd;
	char	*line;

	line = NULL;
//	if (!(ft_init_before_parse(vars)))
//		return (ft_free(vars));
	if ((ft_init_before_parse(vars)))
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		return (ft_free(vars));
	}
	fd = open("src/map.cub", O_RDONLY);
	if (fd == -1)
		return (ft_free(vars));
	while (get_next_line(fd, &line) > 0)
		ft_parse_line(ft_check_line(line), vars, line);
	close(fd);
	fd = open("src/map.cub", O_RDONLY);
	if (fd == -1)
		return (ft_free(vars));
	line = NULL;
	if (ft_is_emptyline_inmap(fd, &line))
	{
		printf("empty line in map ?!!!! \n");
		close(fd);
		return (ft_free(vars));
	}
	close(fd);
	return (1);
}

int	main(void)
{
	t_all	vars;

	if (!(ft_init_start(&vars)))
		return (0);
	if (!(ft_last_check(&vars)))
		return (0);
	ft_fill_sprites(&vars);
	vars.ground.color = ft_rgbtocolor(&vars.ground);
	vars.sky.color = ft_rgbtocolor(&vars.sky);
	ft_define_rslwin(&vars);
	vars.cam.dir = ft_define_cam(&vars);
	ft_draw(&vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_moove_kyhk, &vars);
	ft_draw(&vars);
	mlx_loop(vars.mlx);
	ft_free(&vars);
	return (0);
}
