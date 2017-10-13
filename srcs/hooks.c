#include "../includes/wolf3d.h"
#include <stdio.h>

void		right_left(int keycode, t_mlx *mlx)
{
	if (keycode == 124)
	{
		mlx->old_dirX = mlx->dirX;
		mlx->dirX = mlx->dirX * cos(-mlx->rotSpeed) - mlx->dirY * sin(-mlx->rotSpeed);
		mlx->dirY = mlx->old_dirX * sin(-mlx->rotSpeed) + mlx->dirY * cos(-mlx->rotSpeed);
		mlx->old_planeX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(-mlx->rotSpeed) - mlx->planeY * sin(-mlx->rotSpeed);
		mlx->planeY = mlx->old_planeX * sin(-mlx->rotSpeed) + mlx->planeY * cos(-mlx->rotSpeed);
	}
	else
	{
		mlx->old_dirX = mlx->dirX;
		mlx->dirX = mlx->dirX * cos(mlx->rotSpeed) - mlx->dirY * sin(mlx->rotSpeed);
		mlx->dirY = mlx->old_dirX * sin(mlx->rotSpeed) + mlx->dirY * cos(mlx->rotSpeed);
		mlx->old_planeX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(mlx->rotSpeed) - mlx->planeY * sin(mlx->rotSpeed);
		mlx->planeY = mlx->old_planeX * sin(mlx->rotSpeed) + mlx->planeY * cos(mlx->rotSpeed);
	}
}

void		up_down(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
	{
		if (mlx->map[(int)(mlx->posX + (mlx->dirX * mlx->moveSpeed) * 1.5)][(int)(mlx->posY)] == 0)
			if ((mlx->posX + mlx->dirX * mlx->moveSpeed) >= 1
					&& (mlx->posX + mlx->dirX * mlx->moveSpeed) < mlx->map_width - 1)
				mlx->posX += mlx->dirX * mlx->moveSpeed;
		if (mlx->map[(int)(mlx->posX)][(int)(mlx->posY + (mlx->dirY * mlx->moveSpeed) * 1.5)] == 0)
			if ((mlx->posY + mlx->dirY * mlx->moveSpeed) >= 1
					&& (mlx->posY + mlx->dirY * mlx->moveSpeed) < mlx->map_width - 1)
				mlx->posY += mlx->dirY * mlx->moveSpeed;
	}
	else
	{
		if (mlx->map[(int)(mlx->posX - (mlx->dirX * mlx->moveSpeed) * 1.5)][(int)(mlx->posY)] == 0)
			if ((mlx->posX - mlx->dirX * mlx->moveSpeed) >= 1
					&& (mlx->posX - mlx->dirX * mlx->moveSpeed) < mlx->map_width - 1)
				mlx->posX -= mlx->dirX * mlx->moveSpeed;
		if (mlx->map[(int)(mlx->posX)][(int)(mlx->posY - (mlx->dirY * mlx->moveSpeed) * 1.5)] == 0)
			if ((mlx->posY - mlx->dirY * mlx->moveSpeed) >= 1
					&& (mlx->posY - mlx->dirY * mlx->moveSpeed) < mlx->map_width - 1)
				mlx->posY -= mlx->dirY * mlx->moveSpeed;
	}
}

int			key_press(int keycode, t_mlx *mlx)
{	
	if (keycode == 124 || keycode == 123)
		right_left(keycode, mlx);
	if (keycode == 126 || keycode == 125)
		up_down(keycode, mlx);
	if (keycode == 53)
		hook_close(mlx);
	mlx_clear_window(mlx->mlx, mlx->window);
	delete_image(mlx);
	new_image(mlx);
	algo(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
	mlx_do_sync(mlx->mlx);
	return (0);
}

int			hook_close(t_mlx *mlx)
{
	free(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void		hooks(t_mlx *mlx)
{
	mlx_hook(mlx->window, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->window, 17, 1L << 0, hook_close, mlx);
}