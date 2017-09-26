#include "../includes/lem_in.h"

t_room			*realloc_rooms(t_anthill *anthill, char **lines, int size)
{
	t_room		*new;
	int			i;

	new = (t_room*)malloc(sizeof(t_room) * size);
	i = -1;
	while (++i < size - 1)
	{
		if ((!ft_strcmp(anthill->rooms[i].name, lines[0])) ||
			(ft_atoi(lines[1]) == anthill->rooms[i].x
				&& ft_atoi(lines[2]) == anthill->rooms[i].y))
			ft_error(anthill);
		new[i].name = ft_strdup(anthill->rooms[i].name);
		new[i].x = anthill->rooms[i].x;
		new[i].y = anthill->rooms[i].y;
		new[i].start = anthill->rooms[i].start;
		new[i].end = anthill->rooms[i].end;
		new[i].ants = anthill->rooms[i].ants;
		new[i].cap = anthill->rooms[i].cap;
		free(anthill->rooms[i].name);
	}
	free(anthill->rooms);
	return (new);
}

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
