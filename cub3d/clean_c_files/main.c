/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/07 14:53:59 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{
	int	fd;
	char	*line;
	t_all	vars;
	int	i;

	if (!(ft_init_before_parse(&vars)))
		return (ft_free(&vars));
	if (!(fd = open("map.cub", O_RDONLY)))
		return (0);
	while (get_next_line(fd, &line) > 0)
		ft_parse_line(ft_check_line(line), &vars, line);
	close(fd);
	if (!(fd = open("map.cub", O_RDONLY)))
		return (0);
	line = NULL;
	if (ft_is_emptyline_inmap(fd, &line))
	{
		printf("empty line in map ?!!!! \n");
		return (ft_free(&vars));
	}
	if (!(ft_ismap_walled(vars.map.box)))
	{
		printf("map is not walled ?!!!! \n");
		return (ft_free(&vars));
	}
	ft_replace_mapspace(vars.map.box);
	if (!(ft_init_after_parse(&vars)))
	{
		if (vars.wallface != NULL)
			free(vars.wallface);
		return (0);
	}
	ft_fill_sprites(&vars);
	vars.ground.color = ft_rgbtocolor(&vars.ground);
	vars.sky.color = ft_rgbtocolor(&vars.sky);
	ft_define_rslwin(&vars);
	vars.cam.dir = ft_define_cam(&vars);
	ft_draw(&vars);
	mlx_hook(vars.win, 2, 1L<<0, ft_moove_kyhk, &vars);
	ft_draw(&vars);
	mlx_loop(vars.mlx);
	/*ft_exit(&vars);*/
	return (0);
}
