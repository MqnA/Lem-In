#ifndef LEM_IN_H
# define LEM_IN_H

# include "../LIBFT/libft.h"
# include "limits.h"

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				ants;
	int				start;
	int				end;
	int				cap;
}					t_room;

typedef struct		s_anthill
{
	t_room			*rooms;
	t_list			*step;
	int				**links;
	int				**copy;
	int				*ants;
	int				start_room;
	int				end_room;
	int				n_ants;
	int				n_rooms;
	int				free;
}					t_anthill;

int					check_map(t_anthill *anthill);
int					check_room(char *line);
int					find_rooms(t_list *map);
int					locate_room(t_room *rooms, char *room, int size);
int					**links_init(int size);
void				lem_in(t_anthill *anthill);
void				free_all(t_anthill *anthill);
void				ft_error(t_anthill *anthill);
void				copy_links(t_anthill *anthill);
void				add_room(t_anthill *anthill, char *line,
					int *start, int *end);
void				add_path(t_anthill *anthill, char *line);
void				parser(t_anthill *anthill);
void				ants_init(t_anthill *anthill);
void				get_ants(t_anthill *anthill, char *line);
void				print_path(t_anthill *anthill, int ant, int *parent, int v);
void				print_step(t_anthill *anthill);
void				solve(t_anthill *anthill, int ant_no, int option);
void				update_links(t_anthill *anthill);
t_anthill			*anthill_init(void);
t_room				*realloc_rooms(t_anthill *anthill, char **lines, int size);

#endif
