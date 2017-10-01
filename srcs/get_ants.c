/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:24:15 by mavagner          #+#    #+#             */
/*   Updated: 2017/10/01 04:03:43 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			get_ants(t_anthill *anthill, char *line)
{
	if (anthill->n_ants == 0)
	{
		anthill->n_ants = ft_atoi(line);
		if (anthill->n_ants == -2147483648)
			ft_error(anthill);
		if (!(anthill->ants = (int*)malloc(sizeof(int) * anthill->n_ants)))
			ft_error(anthill);
		if (anthill->n_ants < 1)
			ft_error(anthill);
	}
	else
		ft_error(anthill);
}

void			ants_init(t_anthill *anthill)
{
	int			i;

	i = 0;
	anthill->start_room = anthill->n_rooms;
	while (i < anthill->n_ants)
	{
		anthill->ants[i] = anthill->start_room;
		i++;
	}
}
