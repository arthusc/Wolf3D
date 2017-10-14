/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 22:12:48 by achambon          #+#    #+#             */
/*   Updated: 2017/10/14 22:14:10 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

int		ft_count(char **tab)
{
	int count;

	count = 0;
	while (tab[count] != 0)
		count++;
	return (count);
}

void	*free_tab(char **tmp)
{
	int		i;

	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
	return (NULL);
}

int		**parse_in_int(char **tab, int line_value)
{
	int		**grid;
	char	**tmp;
	int		i;
	int		j;

	i = -1;
	if ((grid = (int **)malloc(sizeof(int*) * line_value)) == NULL)
		return (NULL);
	while (++i < line_value)
	{
		tmp = ft_split(tab[i], " ");
		j = 0;
		if ((grid[i] = (int*)malloc(sizeof(int) * ft_count(tmp) + 1)) == NULL)
			return (NULL);
		while (j < ft_count(tmp))
		{
			grid[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		grid[i][j] = -42;
		tmp = free_tab(tmp);
	}
	return (grid);
}

char	**fill_tab(int line_value, char *file)
{
	int		fd;
	int		i;
	char	**tab;

	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * line_value)) == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (i < line_value)
	{
		get_next_line(fd, &tab[i]);
		i++;
	}
	return (tab);
}

int		parsing(char *filename, t_mlx *mlx)
{
	int		fd;
	char	*buffer;
	char	**tab;
	int		i;

	i = -1;
	fd = open(filename, O_RDONLY);
	mlx->map_width = 0;
	while (get_next_line(fd, &buffer) > 0)
	{
		mlx->map_width++;
		free(buffer);
	}
	close(fd);
	tab = fill_tab(mlx->map_width, filename);
	mlx->map = parse_in_int(tab, mlx->map_width);
	while (++i < mlx->map_width)
		free(tab[i]);
	free(tab);
	return (0);
}
