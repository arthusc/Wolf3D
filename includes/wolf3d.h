/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:06:20 by achambon          #+#    #+#             */
/*   Updated: 2017/10/13 22:14:39 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define HEIGHT 1600.
# define WIDTH  1800.
# define KEYCODE
// # define MAP_WIDTH 0

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>

typedef struct		s_mlx
{
	int 		*mlx;
	int			**map;
	void		*image;
	int 		color;
	char		*image_data;
	int 		*window;
	int 		bpp;
	int 		endian;
	int 		stride;
	int 		map_width;
	double 		posX; 
	double 		posY;
	double 		dirX;
	double 		old_dirX;
	double		dirY;
	double 		planeX;
	double		old_planeX;
	double		planeY;
	double 		time;
	double 		oldTime;
	double 		cameraX;
    double 		rayPosX;
    double 		rayPosY;
    double 		rayDirX;
    double 		rayDirY;
    int 		mapX;
    int 		mapY;
    double		sideDistX;
    double		sideDistY;
    double		deltaDistX;
    double		deltaDistY;
    double		perpWallDist;
    int 		stepX;
    int 		stepY;
    int 		hit;
    int 		side;
    int 	lineHeight;
    int 	drawStart;  
    int 	drawEnd;
	double frameTime;
	double moveSpeed;
	double rotSpeed;      
}					t_mlx;

void				init_map(t_mlx *mlx, int x, int y);
int					ft_countwords(char const *s);
int					*ft_read(char **argv);
int					**ft_map(t_mlx *mlx, int x, int y, char **argv);
void				reset_index_incr_x(int *index1, int *x, int *y,
		char **line);
void	error_arg(void);
void	error_map(void);
void				init_values(t_mlx *mlx);
void 				window_n_image(t_mlx *mlx);
void      algo(t_mlx *mlx);
void		get_colors(t_mlx *mlx);
void		hooks(t_mlx *mlx);
void		right_left(int keycode, t_mlx *mlx);
void		up_down(int keycode, t_mlx *mlx);
int			key_press(int keycode, t_mlx *mlx);
int			hook_close(t_mlx *mlx);
void	*new_image(t_mlx *mlx);
void	*delete_image(t_mlx *mlx);
void	rt_colors(t_mlx *mlx, int x);
void		hooks(t_mlx *mlx);
int			key_press(int keycode, t_mlx *mlx);

#endif
