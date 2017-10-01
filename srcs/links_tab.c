/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:24:24 by mavagner          #+#    #+#             */
/*   Updated: 2017/10/01 01:39:05 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			copy_links(t_anthill *anthill)
{
	int			i;
	int			j;

	i = -1;
	while (++i < anthill->n_rooms)
	{
		j = -1;
		while (++j < anthill->n_rooms)
			anthill->links[i][j] = anthill->copy[i][j];
	}
}

void			update_links(t_anthill *anthill)
{
	int			i;
	int			j;

	i = 0;
	while (i < anthill->n_rooms)
	{
		if (anthill->rooms[i].ants > 0 && i != anthill->start_room
			&& i != anthill->end_room)
		{
			j = 0;
			while (j < anthill->n_rooms)
			{
				if (anthill->links[i][j] != 0)
					anthill->links[i][j]++;
				j++;
			}
		}
		i++;
	}
}

int				**links_init(int size)
{
	int			**links;
	int			i;
	int			j;

	i = -1;
	if (!(links = (int**)malloc(sizeof(int*) * size)))
		return (0);
	while (++i < size)
	{
		j = -1;
		if (!(links[i] = (int*)malloc(sizeof(int) * size)))
			return (0);
		while (++j < size)
			links[i][j] = 0;
	}
	return (links);
}
