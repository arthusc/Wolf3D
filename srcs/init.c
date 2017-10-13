#include "../includes/wolf3d.h"
#include <stdio.h>

void	*delete_image(t_mlx *mlx)
{
	if (mlx->image != NULL)
	{
		if (mlx->image != NULL)
			mlx_destroy_image(mlx->mlx, mlx->image);
		ft_memdel((void **)&mlx->image);
	}
	return (NULL);
}

void	*new_image(t_mlx *mlx)
{
	// if ((mlx->image = ft_memalloc(sizeof(t_mlx))) == NULL)
		// return (NULL);
	if ((mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT))
			== NULL)
		return (delete_image(mlx));
	mlx->image_data = mlx_get_data_addr(mlx->image, &mlx->bpp,
			&mlx->stride, &mlx->endian);
	mlx->bpp /= 8;
	return (mlx->image);
}

void 				window_n_image(t_mlx *mlx)
{
	// printf("%d encore ici\n", mlx->map[2][2]);
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Wolf3D");
	// printf("%d et la\n", mlx->map[2][2]);
	mlx->image = new_image(mlx);
	if (mlx->window == NULL)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		ft_memdel((void **)&mlx);
	}

	// if ((mlx_new_window(mlx->window, WIDTH, HEIGHT, "Wolf3D") == NULL || (mlx->image = new_image(mlx)) == NULL))
	// {
		// printf("%d la\n", mlx->map[2][2]);
		// mlx_destroy_window(mlx->mlx, mlx->window);
		// ft_memdel((void **)&mlx);
	// }
}

void				init_values(t_mlx *mlx)
{
	mlx->posX = 22;
	mlx->posY = 12;  //x and y start position;
	mlx->dirX = -1;
	mlx->dirY = 0; //initial direction vector;
	mlx->planeX = 0;
	mlx->planeY = 0.66; //the 2d raycaster version of camera plane;
	mlx->time = 0; //time of current frame;
	mlx->oldTime = 0; //time of previous frame
}

void				init_map(t_mlx *mlx, int x, int y)
{
	int	i;

	i = 0;
	mlx->map = malloc(sizeof(double*) * y + 1);
	while (i < y)
		mlx->map[i++] = malloc(sizeof(double) * x);
	return ;
}