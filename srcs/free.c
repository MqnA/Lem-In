/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:24:08 by mavagner          #+#    #+#             */
/*   Updated: 2017/09/30 21:24:10 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
