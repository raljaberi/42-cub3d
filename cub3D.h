/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:50:19 by raljaber          #+#    #+#             */
/*   Updated: 2025/02/23 18:27:57 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_HEIGHT 800
# define WIN_WIDTH 1000

# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define ESC 53

# define W 13
# define A 0
# define S 1
# define D 2

# define HEX "0123456789ABCDEF"
# define DEC "0123456789"

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_player
{
	int		compass;
	double	dirx;
	double	diry;
	double	posx;
	double	posy;
	double	plnx;
	double	plny;
	int		stepx;
	int		stepy;
	double	rt_s;
	double	movespeed;
}				t_player;

typedef struct s_ray
{
	int		hit;
	int		side;
	int		mapx;
	int		mapy;
	double	step;
	double	wallx;
	int		color;
	double	texpos;
	int		drawend;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		drawstart;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		wallheight;
	double	perpwalldist;
}			t_ray;

typedef struct s_mlx
{
	void		*mlx;
	int			texx;
	int			texy;
	void		*tex;
	int			*text;
	void		*tex2;
	int			*text2;
	void		*tex3;
	int			*text3;
	void		*tex4;
	int			*text4;
	long int	ccolor;
	long int	fcolor;
	int			drawend;
	void		*mlx_win;
	int			**buffer;
	int			drawstart;
	int			wallheight;
	void		*img;
	int			b;
	int			h;
	int			w;
}			t_mlx;

typedef struct s_all
{
	t_player	*pl;
	t_ray		*ray;
	t_mlx		*mlx;
	char		*map_file;
	char		*mapl;
	char		**splmap;
	char		**textures;
	char		**colors;
	char		**map;
	int			compass_flag;
}			t_all;

void	all_struct_init(t_all *all, t_mlx *mlx, t_ray *ray, t_player *player);
void	init_direction(t_player *player);
void	direction_part1(t_player *player);
void	ft_get_map(t_all *all, char *filename);
char	**ft_split_all(char *str, t_all *all);
void	ft_replace_element(t_all *all);
char	**_2d_array_dup(char **arr, size_t start, size_t size);
char	*ft_line_replace(char *old, char *new);
size_t	ft_arr_len(char **arr);
int		ft_find_index(t_all *all, char **arr, char *s, size_t size);
void	ft_color_parse(t_all *all);
size_t	ft_atoi_index(t_all *all, const char *str, size_t i, int error);
void	ft_map_valid_char(t_all *all, int i, size_t nl);
void	ft_check_walls(t_all *all);
void	ft_check_space(t_all *all, int i, int a);
void	ft_check_zero(t_all *all);
int		check_wall_collision(t_all *all, char c);
void	check_pos(char c, t_all *all);
void	ft_texture(t_all *all);
size_t	ft_linecount(char *str);
void	ft_arr_trim(char **arr);
void	init_imgs(t_all *all);
int		ray_cast(t_all *all, char **map);
void	clearbuffer(t_all *all);
void	init_drawing(t_all *all, int x);
void	init_dist(t_all *all);
void	get_wall_hit(t_all *all, char **map);
void	calc_wall_hit(t_all *all, char **map, int *ii);
void	calc_wall_projection(t_all *all);
void	get_walls(t_all *all, int y, int x, int ii);
void	key_w_s(t_all *all, int keycode);
void	key_a_d(t_all *all, int keycode);
void	key_r_l(t_all *all, int keycode);
int		key(int keycode, t_all *all);
int		ft_destroy_free(t_all *all);
size_t	ft_atoi_index(t_all *all, const char *str, size_t i, int error);
char	*ft_put_nbr(int nbr, char *base, int sign, int i);
void	ft_putnbr_base(int nbr, int nbase, char *num_base, char *base);
char	*ft_rgb_to_hex(t_all *all, char *rgb, size_t i);
void	ft_color_chars_checker(t_all *all, size_t i, size_t a, int comma);
void	ft_color_chars_init_checker(t_all *all);
int		ft_lnbr(int nbr, int base_lenght);
char	*ft_char(char *dest, char src);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_destroy_free(t_all *all);
void	ft_error(t_all *all, int error);
void	ft_free_all(t_all *all);
void	ft_free_arr(char **arr);
void	extra_imgs(t_all *all);
void	drawall(t_all *all, int **buffer);
void	fill_floor_ceil(t_all *all, int y, int x);
void	gettexture(t_all *all, int ii);
char	*extract_line(char **str, t_all *all);

#endif