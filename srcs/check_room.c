#include "../includes/lem_in.h"

int				check_room(char *line)
{
	int			i;
	char		**lines;

	i = 0;
	lines = ft_strsplit(line, ' ');
	while (lines[i])
		i++;
	if (lines[0][0] == 'L' || !is_digit(lines[1]) || !is_digit(lines[2]))
		return (0);
	return (1);
}
