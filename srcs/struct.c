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

int				locate_room(t_room *rooms, char *room, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		if (!strcmp(rooms[i].name, room))
			return (i);
		i++;
	}
	return (-1);
}
