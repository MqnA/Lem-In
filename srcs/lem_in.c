#include "../includes/lem_in.h"

void			lem_in(t_anthill *anthill)
{
	int			check;
	int			i;

	i = 0;
	check = 0;
	while (anthill->rooms[anthill->end_room].ants != anthill->n_ants)
	{
		i = -1;
		while (++i < anthill->n_ants)
		{
			if (check == 0)
				print_step(anthill);
			copy_links(anthill);
			update_links(anthill);
			solve(anthill, i, 1);
			check = 1;
		}
		ft_printf("\n");
	}
}
