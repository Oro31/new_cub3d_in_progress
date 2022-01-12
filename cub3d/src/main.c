/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/12 19:41:06 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_exit(t_all *vars)
{
	ft_free(vars);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	return (0);
}

static int	ft_last_check(t_all *vars)
{
	if (!(ft_ismap_walled(vars->map.box)))
	{
		printf("map is not walled ?!!!! \n");
		return (0);
	}
	ft_replace_mapspace(vars->map.box);
	if (!(ft_init_after_parse(vars)))
		return (0);
	return (1);
}

static int	ft_init_start(t_all *vars, char *map_file_path)
{
	int		fd;
	char	*line;

	line = NULL;
	if (!(ft_init_before_parse(vars)))
		return (0);
	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &line) > 0)
		ft_parse_line(ft_check_line(line), vars, line);
	close(fd);
	free(line);
	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	if (ft_is_emptyline_inmap(fd))
	{
		printf("empty line in map ?!!!! \n");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

static int	ft_handle_argv(char *argv)
{
	int	i;
	int	fd;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] != 'b' || argv[i - 2] != 'u' || argv[i - 3] != 'c'
		|| argv[i - 4] != '.')
		return (ft_error_msg(1));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		return (ft_error_msg(2));
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_all	vars;

	if (argc != 2)
		return (0);
	if (!ft_handle_argv(argv[1]))
		return (0);
	if (!(ft_init_start(&vars, argv[1])))
		return (ft_exit(&vars));
	if (!(ft_last_check(&vars)))
		return (ft_exit(&vars));
	if (!ft_fill_sprites(&vars))
		return (ft_exit(&vars));
	vars.ground.color = ft_rgbtocolor(&vars.ground);
	vars.sky.color = ft_rgbtocolor(&vars.sky);
	ft_define_rslwin(&vars);
	vars.cam.dir = ft_define_cam(&vars);
	ft_draw(&vars);
	mlx_hook(vars.win, 3, 1L << 1, ft_moove_kyhk, &vars);
	mlx_hook(vars.win, 33, 1L << 17, ft_redcross, &vars);
	mlx_hook(vars.win, 9, 1L << 21, ft_minimize, &vars);
	mlx_loop(vars.mlx);
	ft_free(&vars);
	return (0);
}
