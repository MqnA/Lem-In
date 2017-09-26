#include "../includes/lem_in.h"

void			free_all(t_anthill *anthill)
{
	int			i;

	i = 0;
	if (anthill->free)
	{
		i = 0;
		while (i < anthill->n_rooms)
		{
			free(anthill->links[i]);
			free(anthill->copy[i]);
			i++;
		}
		free(anthill->rooms);
		free(anthill->links);
		free(anthill->copy);
		free(anthill->ants);
	}
	free(anthill);
}
