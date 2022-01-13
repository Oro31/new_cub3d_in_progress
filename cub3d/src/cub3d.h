/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:56:50 by rvalton           #+#    #+#             */
/*   Updated: 2022/01/13 18:00:04 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "../mlx_linux/mlx.h"
# define APPROXI 0.0001

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			e;
}			t_data;

typedef struct s_spr
{
	char		**path;
	t_data		*data;
	int			nbspr;
}			t_spr;

typedef struct s_rsl
{
	int		w;
	int		h;
}			t_rsl;

typedef struct s_rgb
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	int			color;
	int			error;
}			t_rgb;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_cam
{
	t_pos		pos;
	char		dir;
}			t_cam;

typedef struct s_map
{
	char		**box;
}			t_map;

typedef struct s_ray
{
	double		y;
	double		x;
	int			sy;
	int			sx;
	float		t;
	float		a;
	float		f;
	int			*xtex;
}			t_ray;

typedef struct s_all
{
	void		*mlx;
	void		*win;
	int			*wallface;
	t_data		img;
	t_spr		spr;
	t_map		map;
	t_rsl		rsl;
	t_cam		cam;
	t_rgb		ground;
	t_rgb		sky;
	t_ray		ray;
}			t_all;

int		ft_malloc_dblchar(char ***tmp, int size);
int		ft_malloc_splchar(char **tmp, int size);
int		ft_malloc_dblint(int ***tmp, int size);
int		ft_malloc_splint(int **tmp, int size);

void	ft_memset_spr_data(t_data *s, int n);

void	ft_init_pointer(t_all *vars);
int		ft_init_before_parse(t_all *vars);
int		ft_init_after_parse(t_all *vars);

int		ft_error_msg(int err_code);

void	ft_parse_line(int checkline, t_all *vars, char *line);

char	*ft_parse_path(char *line, int iswall);
int		ft_parse_tex(char *line, char **tpath);

void	ft_parse_rsl(char *line, t_rsl *rsl);
void	ft_define_rslwin(t_all *vars);

void	ft_rgb_fill(t_rgb *rgb, char *line);

int		ft_rgbtocolor(t_rgb *rgb);
t_rgb	*ft_colortorgb(int color);

void	ft_mymlx_pixelput(t_all *vars, t_data *data);
int		ft_myxpm_pixelput(t_all *vars, int e, t_pos *pos);
int		ft_get_pxy(int xy, int wh);
int		ft_get_xpm_pixel(t_data *data, int x, int y);

int		ft_istex_line(char *line);
int		ft_isrgb_line(char *line);
int		ft_ismap_line(char *line);
int		ft_check_line(char *line);

int		ft_ismap_member(char c);
int		ft_len_mpline(char *line);
char	*ft_linemap_realloc(char **map, int i);
char	*ft_linemap_fill(char *line, int maxlen);
char	**ft_parse_map(char *line, char **map);

int		ft_lenmax_mpline(char **map);
int		ft_is_space_diagwalled_tool(char **map, int i, int j);
int		ft_is_space_diagwalled(char **map, int i, int j, int len);
int		ft_is_space_walled(char**map, int i, int j, int len);
int		ft_ismap_walled(char **map);

int		ft_isdigit(int c);

int		ft_fill_sprites(t_all *vars);

void	ft_put_pixel_on_img(t_data *img, int color, int x, int y);
int		ft_get_visual(t_all *vars);
int		ft_draw(t_all *vars);

void	ft_free_sprites(t_all *vars);
void	ft_free_map(t_map *map);
int		ft_free(t_all *vars);

int		ft_isdir(char c);
char	ft_define_cam(t_all *vars);
float	ft_dir_to_fov(char dir);
char	ft_fov_to_dir(float fov);

double	ft_ne_hor_inte(t_all *vars, float angle, t_pos *xdm, int i);
double	ft_nw_hor_inte(t_all *vars, float angle, t_pos *xdm, int i);
double	ft_sw_hor_inte(t_all *vars, float angle, t_pos *xdm, int i);
double	ft_se_hor_inte(t_all *vars, float angle, t_pos *xdm, int i);
double	ft_hor_intersect(t_all *vars, float angle, t_pos *xdm, int i);

double	ft_ne_vert_inte(t_all *vars, float angle, t_pos *xdm, int i);
double	ft_nw_vert_inte(t_all *vars, float angle, t_pos *xdm, int i);
double	ft_sw_vert_inte(t_all *vars, float angle, t_pos *xdm, int i);
double	ft_se_vert_inte(t_all *vars, float angle, t_pos *xdm, int i);
double	ft_vert_intersect(t_all *vars, float angle, t_pos *xdm, int i);

void	ft_check_maplimites(t_all *vars, t_ray *ray);
float	ft_onlyvert_inte(t_all *vars, float angle, t_pos *xdm, int i);
float	ft_onlyhor_inte(t_all *vars, float angle, t_pos *xdm, int i);
double	ft_len_clst_wall(t_all *vars, int i);
void	ft_find_walls(t_all *vars, double *wall);

void	ft_replace_mapspace(char **map);
int		ft_is_emptyline_inmap(int fd);

void	ft_unif_walls(double *wall, int i);

double	ft_new_ver_inte(t_all *vars, t_ray *ray, int i);
double	ft_new_hor_inte(t_all *vars, t_ray *ray, int i);
int		ft_check_wall(t_all *vars, t_ray *ray, char c, int i);
void	ft_define_ray(t_ray *ray, char c);
int		ft_new_check_maplimites(t_all *vars, int *x, int *y);

int		ft_redcross(t_all *vars);
int		ft_minimize(t_all *vars);

void	ft_close(t_all *vars);
void	ft_turn(t_all *vars, char c);
void	ft_moove(t_all *vars, char c);
int		ft_moove_kyhk(int keycode, t_all *vars);

int		ft_is_notwall(t_all *vars, char c, int s);
void	ft_avancer(t_all *vars);
void	ft_reculer(t_all *vars);
void	ft_lateral_gauche(t_all *vars);
void	ft_lateral_droite(t_all *vars);

#endif
