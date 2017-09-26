#include "libft.h"

void	free_2d(char **lines)
{
	int i;

	i = 0;
	while (lines[i])
	{
		ft_bzero(lines[i], ft_strlen(lines[i]));
		free(lines[i]);
		i++;
	}
	free(lines);
	lines = NULL;
}
