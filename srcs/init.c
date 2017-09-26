#include "../includes/lem_in.h"

t_anthill			*anthill_init(void)
{
	t_anthill		*anthill;

	anthill = (t_anthill*)malloc(sizeof(t_anthill));
	anthill->links = NULL;
	anthill->copy = NULL;
	anthill->rooms = NULL;
	anthill->step = NULL;
	anthill->ants = NULL;
	anthill->start_room = 0;
	anthill->end_room = 0;
	anthill->n_ants = 0;
	anthill->n_rooms = 0;
	anthill->free = 0;
	return (anthill);
}
