/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:04:57 by achambon          #+#    #+#             */
/*   Updated: 2017/10/13 22:18:19 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

void				wolf(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	init_values(mlx);
	// printf("%d ici\n", mlx->map[2][2]);
	window_n_image(mlx);
	// printf("%d la", mlx->map[2][2]);
	// printf("%d ici\n", mlx->map[2][2]);
	algo(mlx);
}

int					main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		*count_word_n_line;
	if (argc != 2)
		error_arg();
	if (!(count_word_n_line = ft_read(argv)))
		error_map();
	count_word_n_line = ft_read(argv);
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	ft_map(mlx, count_word_n_line[0], count_word_n_line[1], argv);
	// printf("%d la\n", mlx->map[2][2]);
	// hooks(mlx);
	wolf(mlx);
	hooks(mlx);
	// printf("%d ici\n", mlx->map[2][2]);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);	
	// printf("%d la\n", mlx->map[2][2]);
	mlx_loop(mlx->mlx);
	free(mlx);
	return (0);
}