/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 20:24:28 by achambon          #+#    #+#             */
/*   Updated: 2017/10/14 22:00:54 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void				put_pixel_mlx(t_mlx *mlx, int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int *)(mlx->image_data + ((x + y * (int)WIDTH) * mlx->bpp)) = mlx->color;
}

void				rt_colors_2(t_mlx *mlx, int x, int y, int j)
{
	while (y++ <= j)
		put_pixel_mlx(mlx, x, y);
	y = mlx->drawstart + 1;
	mlx->color = 0xfc6472;
	while (y-- >= 0)
		put_pixel_mlx(mlx, x, y);
	y = mlx->drawend;
	mlx->color = 0xf4a32e;
	while (y++ <= HEIGHT && y >= 0)
		put_pixel_mlx(mlx, x, y);
}

void				rt_colors(t_mlx *mlx, int x)
{
	int y;
	int j;

	y = mlx->drawstart;
	j = mlx->drawend;
	if (mlx->map[mlx->mapx][mlx->mapy] == 1)
	{
		if (mlx->stepx == -1 && mlx->stepy == -1)
			mlx->color = (mlx->side == 1) ? 0xff7fcf : 0xaa60ff;
		else if (mlx->stepx == 1 && mlx->stepy == -1)
			mlx->color = (mlx->side == 1) ? 0xff7fcf : 0xb77aff;
		else if (mlx->stepx == -1 && mlx->stepy == 1)
			mlx->color = (mlx->side == 1) ? 0xff93d7 : 0xaa60ff;
		else if (mlx->stepx == 1 && mlx->stepy == 1)
			mlx->color = (mlx->side == 1) ? 0xff93d7 : 0xb77aff;
	}
	rt_colors_2(mlx, x, y, j);
}
