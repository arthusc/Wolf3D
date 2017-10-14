/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:06:20 by achambon          #+#    #+#             */
/*   Updated: 2017/10/14 22:07:24 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define HEIGHT 1600.
# define WIDTH  1800.
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>

typedef struct		s_mlx
{
	int				*mlx;
	int				**map;
	void			*image;
	int				color;
	char			*image_data;
	int				*window;
	int				bpp;
	int				endian;
	int				stride;
	int				map_width;
	double			posx;
	double			posy;
	double			dirx;
	double			old_dirx;
	double			diry;
	double			planex;
	double			old_planex;
	double			planey;
	double			time;
	double			oldtime;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			frametime;
	double			movespeed;
	double			sprint;
	double			rotspeed;
}					t_mlx;

void				init_map(t_mlx *mlx, int x, int y);
int					parsing(char *filename, t_mlx *mlx);
char				**fill_tab(int line_value, char *file);
int					**parse_in_int(char **tab, int line_value);
int					ft_count(char **tab);
void				test_print_tab(int **grid, int line_value);
void				error_arg(void);
void				init_values(t_mlx *mlx);
void				window_n_image(t_mlx *mlx);
void				algo(t_mlx *mlx);
void				get_colors(t_mlx *mlx);
void				hooks(t_mlx *mlx);
void				right_left(int keycode, t_mlx *mlx);
void				up_down(int keycode, t_mlx *mlx);
int					key_press(int keycode, t_mlx *mlx);
int					hook_close(t_mlx *mlx);
void				*new_image(t_mlx *mlx);
void				*delete_image(t_mlx *mlx);
void				rt_colors(t_mlx *mlx, int x);
void				hooks(t_mlx *mlx);
int					key_press(int keycode, t_mlx *mlx);

#endif
