#include "../includes/wolf3d.h"

int					ft_countwords(char const *s)
{
	int i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else
		{
			words++;
			while (s[i] != ' ' && s[i])
				i++;
		}
	}
	return (words);
}

void				reset_index_incr_x(int *index1, int *x, int *y, char **line)
{
	*index1 = 0;
	*x += 1;
	*y = 0;
	*line = NULL;
	free(*line);
}