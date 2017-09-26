#include "../includes/lem_in.h"

void		add_path(t_anthill *anthill, char *line)
{
	char	**lines;
	int		x;
	int		y;

	if (anthill->n_rooms == 0 || anthill->n_ants == 0)
		ft_error(anthill);
	if (anthill->links == NULL)
	{
		(anthill->links) = links_init(anthill->n_rooms);
		(anthill->copy) = links_init(anthill->n_rooms);
		anthill->free = 1;
	}
	lines = ft_strsplit(line, '-');
	if ((x = locate_room(anthill->rooms, lines[0], anthill->n_rooms)) == -1)
		ft_error(anthill);
	if ((y = locate_room(anthill->rooms, lines[1], anthill->n_rooms)) == -1)
		ft_error(anthill);
	anthill->links[x][y] = 1;
	anthill->links[y][x] = 1;
	anthill->copy[x][y] = 1;
	free_2d(lines);
}
