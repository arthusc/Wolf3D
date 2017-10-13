/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 20:24:28 by achambon          #+#    #+#             */
/*   Updated: 2017/10/13 21:55:25 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void				put_pixel_mlx(t_mlx *mlx, int x, int y)
{
	int i;

	if (x >= 900 || x < 0 || y >= 900 || y < 0)
		return ;
	i = x * 4 + y * mlx->stride;
	mlx->image_data[i] = (mlx->color);
	mlx->image_data[++i] = ((mlx->color >> 8));
	mlx->image_data[++i] = (mlx->color >> 16);
}

void	rt_colors(t_mlx *mlx, int x)
{
	// X1 = i;
	int y;
	int j;

	y = mlx->drawStart;
	j = mlx->drawEnd;
	if (mlx->map[mlx->mapX][mlx->mapY] == 1)
	{
		if (mlx->stepX == -1 && mlx->stepY == -1)
			mlx->color = (mlx->side == 1) ? 0x594F4F / 2 : 0x9DE0AD;
		else if (mlx->stepX == 1 && mlx->stepY == -1)
			mlx->color = (mlx->side == 1) ? 0x594F4F / 2 : 0xE5FCC2;
		else if (mlx->stepX == -1 && mlx->stepY == 1)
			mlx->color = (mlx->side == 1) ? 0x45ADA8 : 0x9DE0AD;
		else if (mlx->stepX == 1 && mlx->stepY == 1)
			mlx->color = (mlx->side == 1) ? 0x45ADA8 : 0xE5FCC2;
	}
	while (y++ <= j)
		put_pixel_mlx(mlx, x, y);
	y++;
	mlx->color = 0x594F4F;
	while (y-- >= 0)
		put_pixel_mlx(mlx, x, y);
	y = j;
	mlx->color = 0x547980;
	while (y++ <= HEIGHT && y >= 0)
		put_pixel_mlx(mlx, x, y);
}