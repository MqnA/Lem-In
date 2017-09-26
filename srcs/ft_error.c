#include "../includes/lem_in.h"

void			ft_error(t_anthill *anthill)
{
	write(1, "Error: Invalid map.\n", 22);
	free_all(anthill);
	exit(0);
}
