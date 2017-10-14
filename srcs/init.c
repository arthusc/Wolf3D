/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 22:12:17 by achambon          #+#    #+#             */
/*   Updated: 2017/10/14 22:12:33 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

void				*delete_image(t_mlx *mlx)
{
	if (mlx->image != NULL)
	{
		if (mlx->image != NULL)
			mlx_destroy_image(mlx->mlx, mlx->image);
	}
	return (NULL);
}

void				*new_image(t_mlx *mlx)
{
	if ((mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT))
			== NULL)
		return (delete_image(mlx));
	mlx->image_data = mlx_get_data_addr(mlx->image, &mlx->bpp,
			&mlx->stride, &mlx->endian);
	mlx->bpp /= 8;
	return (mlx->image);
}

void				window_n_image(t_mlx *mlx)
{
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Wolf3D");
	mlx->image = new_image(mlx);
}

void				init_values(t_mlx *mlx)
{
	mlx->posx = 2.5;
	mlx->posy = 2.5;
	mlx->dirx = -1;
	mlx->diry = 0;
	mlx->planex = 0;
	mlx->planey = 0.66;
	mlx->time = 0;
	mlx->oldtime = 0;
	mlx->sprint = 5;
}

void				init_map(t_mlx *mlx, int x, int y)
{
	int	i;

	i = 0;
	mlx->map = malloc(sizeof(int*) * y + 1);
	while (i < y)
		mlx->map[i++] = malloc(sizeof(double) * x);
	return ;
}
