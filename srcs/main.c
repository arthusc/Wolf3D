/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:04:57 by achambon          #+#    #+#             */
/*   Updated: 2017/10/14 22:17:34 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

int					hook_close(t_mlx *mlx)
{
	free(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void				error_parse(void)
{
	write(1, "error parse\n", 12);
	write(1, "Invalid characters in Get_next_line\n", 18);
}

void				error_arg(void)
{
	write(1, "error argv\n", 12);
	write(1, "Usage : <filename> only\n", 18);
	exit(1);
}

void				wolf(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	init_values(mlx);
	window_n_image(mlx);
	algo(mlx);
}

int					main(int argc, char **argv)
{
	t_mlx	*mlx;
	char	*filename;

	if (argc != 1 || !(argv))
		error_arg();
	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (0);
	filename = "maps/map1.w3d";
	if (parsing(filename, mlx) == 0)
		printf("parsing -> OK!\n");
	wolf(mlx);
	hooks(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
	mlx_loop(mlx->mlx);
	free(mlx);
	return (0);
}
