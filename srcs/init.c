/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:24:18 by mavagner          #+#    #+#             */
/*   Updated: 2017/10/01 12:40:58 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_anthill			*anthill_init(void)
{
	t_anthill		*anthill;

	if (!(anthill = (t_anthill*)malloc(sizeof(t_anthill))))
		return (NULL);
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
	anthill->check_start = 0;
	anthill->check_end = 0;
	return (anthill);
}
