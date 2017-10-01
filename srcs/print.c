/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:24:31 by mavagner          #+#    #+#             */
/*   Updated: 2017/10/01 11:37:57 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			print_anthill(t_anthill *anthill)
{
	t_list		*tmp;

	while (anthill->step != NULL)
	{
		tmp = anthill->step;
		ft_printf("%s\n", tmp->content);
		free(tmp->content);
		free(tmp);
		anthill->step = anthill->step->next;
	}
	ft_printf("\n");
}

void			print_path(t_anthill *anthill, int ant, int *parent, int v)
{
	static int	check;

	check = 0;
	if (parent[v] == -1)
		return ;
	print_path(anthill, ant, parent, parent[v]);
	check++;
	if (check == 1)
	{
		if (anthill->rooms[v].ants >= anthill->rooms[v].cap &&
			(v != anthill->start_room && v != anthill->end_room))
			return ;
		anthill->rooms[v].ants++;
		anthill->rooms[anthill->ants[ant]].ants--;
		anthill->ants[ant] = v;
		ft_printf("L%d-%s ", ant + 1, anthill->rooms[v].name);
	}
}
