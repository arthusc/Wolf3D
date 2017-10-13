#include "../includes/wolf3d.h"

int					ft_open(char *str)
{
	int fd;

	if (!(fd = open(str, O_RDONLY)))
	{
		ft_putendl("error opening the file");
		exit(-1);
	}
	return (fd);
}

int					*ft_read(char **argv)
{
	int		fd;
	char	*line;
	int		*index;

	index = malloc(sizeof(int) * 2);
	index[0] = 0;
	index[1] = 0;
	fd = ft_open(argv[1]);
	while (get_next_line(fd, &line) == 1)
	{
		if (index[0] == 0)
			index[0] = ft_countwords(line);
		if (ft_countwords(line) < index[0])
		{
			ft_putendl("Found wrong line length. Exiting.");
			exit(-1);
		}
		index[1]++;
		line = NULL;
		free(line);
	}
	close(fd);
	return (index);
}

int					**ft_map(t_mlx *mlx, int x, int y, char **argv)
{
	int		index_n_fd[2];
	char	*line;

	init_map(mlx, x, y);
	x = 0;
	y = 0;
	index_n_fd[0] = 0;
	index_n_fd[1] = ft_open(argv[1]);
	while (get_next_line(index_n_fd[1], &line))
	{
		while (line[index_n_fd[0]] != '\0')
			if (line[index_n_fd[0]] == ' ')
				index_n_fd[0]++;
			else
			{
				mlx->map[x][y] = ft_atoi(&line[index_n_fd[0]]);
				y++;
				while (line[index_n_fd[0]] != ' ' && line[index_n_fd[0]])
					index_n_fd[0]++;
			}
		reset_index_incr_x(&index_n_fd[0], &x, &y, &line);
	}
	mlx->map_width = x;
	mlx->map[x] = NULL;
	close(index_n_fd[1]);
	return (0);
}