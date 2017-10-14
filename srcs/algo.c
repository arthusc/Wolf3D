/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 20:01:51 by achambon          #+#    #+#             */
/*   Updated: 2017/10/14 21:49:37 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <time.h>

void		calculate_distance_height_pixel(t_mlx *mlx, int x)
{
	mlx->lineheight = (int)(HEIGHT / mlx->perpwalldist);
	mlx->drawstart = -mlx->lineheight / 2 + HEIGHT / 2;
	if (mlx->drawstart < 0)
		mlx->drawstart = 0;
	mlx->drawend = mlx->lineheight / 2 + HEIGHT / 2;
	if (mlx->drawend >= HEIGHT)
		mlx->drawend = HEIGHT - 1;
	rt_colors(mlx, x);
	mlx->oldtime = mlx->time;
	mlx->time = clock();
	mlx->frametime = (mlx->time - mlx->oldtime) / 1000.0;
	mlx->movespeed = mlx->frametime * mlx->sprint;
	mlx->rotspeed = mlx->frametime * 3.0;
}

void		digital_differential_analysis(t_mlx *mlx)
{
	if (mlx->sidedistx < mlx->sidedisty)
	{
		mlx->sidedistx = mlx->sidedistx + mlx->deltadistx;
		mlx->mapx = mlx->mapx + mlx->stepx;
		mlx->side = 0;
	}
	else
	{
		mlx->sidedisty += mlx->deltadisty;
		mlx->mapy += mlx->stepy;
		mlx->side = 1;
	}
	if (mlx->map[mlx->mapx][mlx->mapy] > 0)
		mlx->hit = 1;
}

void		check_ray(t_mlx *mlx)
{
	if (mlx->raydirx < 0)
	{
		mlx->stepx = -1;
		mlx->sidedistx = (mlx->rayposx - mlx->mapx) * mlx->deltadistx;
	}
	else
	{
		mlx->stepx = 1;
		mlx->sidedistx = (mlx->mapx + 1.0 - mlx->rayposx) * mlx->deltadistx;
	}
	if (mlx->raydiry < 0)
	{
		mlx->stepy = -1;
		mlx->sidedisty = (mlx->rayposy - mlx->mapy) * mlx->deltadisty;
	}
	else
	{
		mlx->stepy = 1;
		mlx->sidedisty = (mlx->mapy + 1.0 - mlx->rayposy) * mlx->deltadisty;
	}
}

void		loop_init(t_mlx *mlx, int x)
{
	mlx->camerax = 2 * x / WIDTH - 1;
	mlx->rayposx = mlx->posx;
	mlx->rayposy = mlx->posy;
	mlx->raydirx = mlx->dirx + mlx->planex * mlx->camerax;
	mlx->raydiry = mlx->diry + mlx->planey * mlx->camerax;
	mlx->mapx = (int)mlx->rayposx;
	mlx->mapy = (int)mlx->rayposy;
	mlx->deltadistx = sqrt(1 + (mlx->raydiry * mlx->raydiry) /
			(mlx->raydirx * mlx->raydirx));
	mlx->deltadisty = sqrt(1 + (mlx->raydirx * mlx->raydirx) /
			(mlx->raydiry * mlx->raydiry));
	mlx->hit = 0;
	mlx->side = 0;
	check_ray(mlx);
}

void		algo(t_mlx *mlx)
{
	int x;

	x = 0;
	while (x < WIDTH)
	{
		loop_init(mlx, x);
		while (mlx->hit == 0)
			digital_differential_analysis(mlx);
		if (mlx->side == 0)
			mlx->perpwalldist = (mlx->mapx - mlx->rayposx +
					(1 - mlx->stepx) / 2) / mlx->raydirx;
		else
			mlx->perpwalldist = (mlx->mapy - mlx->rayposy +
					(1 - mlx->stepy) / 2) / mlx->raydiry;
		calculate_distance_height_pixel(mlx, x);
		x++;
	}
}
