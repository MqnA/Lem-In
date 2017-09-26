#include "../includes/lem_in.h"

void			parse_cmd(t_anthill *anthill, char *line, int *start, int *end)
{
	if (0 == ft_strcmp("##start", line))
		*start = 1;
	if (0 == ft_strcmp("##end", line))
		*end = 1;
	if (anthill->n_ants == 0)
		ft_error(anthill);
	if (line[1] != '#')
		return ;
}

void			parse_line(t_anthill *anthill, char *line, int *start, int *end)
{
	if (line[0] == '#')
		parse_cmd(anthill, line, start, end);
	else if (ft_strchr(line, '-'))
		add_path(anthill, line);
	else if (is_digit(line))
		get_ants(anthill, line);
	else
		add_room(anthill, line, start, end);
}

void			parser(t_anthill *anthill)
{
	char		*line;
	int			start;
	int			end;

	start = 0;
	end = 0;
	while (get_next_line(0, &line) != 0)
	{
		if ((start == 1 && anthill->start_room != 0) || (end == 1
			&& anthill->end_room != 0))
			ft_error(anthill);
		if ((start || end) && (line[0] == '#' || ft_strchr(line, '-')))
			ft_error(anthill);
		parse_line(anthill, line, &start, &end);
		ft_lstpush(&anthill->step, line, ft_strlen(line));
		free(line);
	}
}

int				main(void)
{
	t_anthill	*anthill;

	anthill = anthill_init();
	parser(anthill);
	if (0 == check_map(anthill))
		ft_error(anthill);
	anthill->rooms[anthill->start_room].ants = anthill->n_ants;
	lem_in(anthill);
	free_all(anthill);
	return (0);
}
