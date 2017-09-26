#include "../includes/lem_in.h"

void			get_ants(t_anthill *anthill, char *line)
{
	if (anthill->n_ants == 0)
	{
		anthill->n_ants = ft_atoi(line);
		anthill->ants = (int*)malloc(sizeof(int) * anthill->n_ants);
		if (anthill->n_ants < 1)
			ft_error(anthill);
	}
	else
		ft_error(anthill);
}

void			ants_init(t_anthill *anthill)
{
	int			i;

	i = 0;
	anthill->start_room = anthill->n_rooms;
	while (i < anthill->n_ants)
	{
		anthill->ants[i] = anthill->start_room;
		i++;
	}
}
