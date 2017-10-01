/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:24:26 by mavagner          #+#    #+#             */
/*   Updated: 2017/10/01 13:11:23 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			parse_line(t_anthill *anthill, char *line, int *start, int *end)
{
	static int isFirst[2] = {0, 0};

	if (line[0] == '#')
	{
		if (ft_strcmp("##start", line) == 0)
		{
			*start = 1;
			++isFirst[0];
			if (isFirst[0] == 2)
				ft_error(anthill);
		}
		if (ft_strcmp("##end", line) == 0)
		{
			*end = 1;
			++isFirst[1];
			if (isFirst[1] == 2)
				ft_error(anthill);
		}
	}
	else if (ft_strchr(line, '-'))
		add_path(anthill, line);
	else if (is_digit(line))
		get_ants(anthill, line);
	else if (1 == check_room(anthill, line))
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
		if ((start || end) && (line[0] == '#' || ft_strchr(line, '-')))
			ft_error(anthill);
		if ((start == 1 && anthill->start_room != 0) || (end == 1
					&& anthill->end_room != 0))
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
