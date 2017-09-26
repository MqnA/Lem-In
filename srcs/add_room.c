#include "../includes/lem_in.h"

void			add_room(t_anthill *anthill, char *line, int *start, int *end)
{
	char		**lines;

	if (anthill->n_ants == 0 || !(check_room(line)))
		ft_error(anthill);
	if (*start == 1)
		ants_init(anthill);
	if (*end == 1)
		anthill->end_room = anthill->n_rooms;
	lines = ft_strsplit(line, ' ');
	anthill->rooms = realloc_rooms(anthill, lines, anthill->n_rooms + 1);
	anthill->rooms[anthill->n_rooms].name = ft_strdup(lines[0]);
	anthill->rooms[anthill->n_rooms].x = ft_atoi(lines[1]);
	anthill->rooms[anthill->n_rooms].y = ft_atoi(lines[2]);
	anthill->rooms[anthill->n_rooms].ants = 0;
	anthill->rooms[anthill->n_rooms].cap = 1;
	anthill->rooms[anthill->n_rooms].start = *start;
	anthill->rooms[anthill->n_rooms].end = *end;
	*start = 0;
	*end = 0;
	anthill->n_rooms++;
	free_2d(lines);
}
