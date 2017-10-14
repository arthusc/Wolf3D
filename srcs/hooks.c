/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 19:40:35 by achambon          #+#    #+#             */
/*   Updated: 2017/10/14 22:11:15 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

void		just_right(t_mlx *mlx)
{
	mlx->old_dirx = mlx->dirx;
	mlx->dirx = mlx->dirx * cos(mlx->rotspeed) - mlx->diry * sin(mlx->rotspeed);
	mlx->diry = mlx->old_dirx * sin(mlx->rotspeed) + mlx->diry *
		cos(mlx->rotspeed);
	mlx->old_planex = mlx->planex;
	mlx->planex = mlx->planex * cos(mlx->rotspeed) - mlx->planey *
		sin(mlx->rotspeed);
	mlx->planey = mlx->old_planex * sin(mlx->rotspeed) + mlx->planey *
		cos(mlx->rotspeed);
}

void		right_left(int keycode, t_mlx *mlx)
{
	if (keycode == 124)
	{
		mlx->old_dirx = mlx->dirx;
		mlx->dirx = mlx->dirx * cos(-mlx->rotspeed) - mlx->diry *
			sin(-mlx->rotspeed);
		mlx->diry = mlx->old_dirx * sin(-mlx->rotspeed) + mlx->diry *
			cos(-mlx->rotspeed);
		mlx->old_planex = mlx->planex;
		mlx->planex = mlx->planex * cos(-mlx->rotspeed) - mlx->planey *
			sin(-mlx->rotspeed);
		mlx->planey = mlx->old_planex * sin(-mlx->rotspeed) + mlx->planey *
			cos(-mlx->rotspeed);
	}
	else
		just_right(mlx);
}

void		up_down(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
	{
		if (mlx->map[(int)(mlx->posx +
					(mlx->dirx * mlx->movespeed) * 1.5)][(int)(mlx->posy)] == 0)
			mlx->posx += mlx->dirx * mlx->movespeed;
		if (mlx->map[(int)(mlx->posx)][(int)(mlx->posy +
					(mlx->diry * mlx->movespeed) * 1.5)] == 0)
			mlx->posy += mlx->diry * mlx->movespeed;
	}
	else
	{
		if (mlx->map[(int)(mlx->posx - (mlx->dirx * mlx->movespeed) *
					1.5)][(int)(mlx->posy)] == 0)
			mlx->posx -= mlx->dirx * mlx->movespeed;
		if (mlx->map[(int)(mlx->posx)][(int)(mlx->posy - (mlx->diry *
						mlx->movespeed) * 1.5)] == 0)
			mlx->posy -= mlx->diry * mlx->movespeed;
	}
}

int			key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 257)
		mlx->sprint = mlx->sprint == 15.0 ? 5.0 : 15.0;
	if (keycode == 124 || keycode == 123)
		right_left(keycode, mlx);
	if (keycode == 126 || keycode == 125)
		up_down(keycode, mlx);
	if (keycode == 53)
		hook_close(mlx);
	mlx_destroy_image(mlx->mlx, mlx->image);
	new_image(mlx);
	algo(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
	mlx_do_sync(mlx->mlx);
	return (0);
}

void		hooks(t_mlx *mlx)
{
	mlx_hook(mlx->window, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->window, 17, 1L << 0, hook_close, mlx);
}
