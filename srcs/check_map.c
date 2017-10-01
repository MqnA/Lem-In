/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:24:00 by mavagner          #+#    #+#             */
/*   Updated: 2017/10/01 12:46:37 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				check_map(t_anthill *anthill)
{
	int			i;
	int			start;
	int			end;

	end = 0;
	start = 0;
	i = -1;
	if (anthill->n_rooms == 0 || anthill->links == NULL)
		return (0);
	solve(anthill, 0, 0);
	while (i < anthill->n_rooms)
	{
		if (anthill->rooms[i].start == 1)
			start++;
		if (anthill->rooms[i].end == 1)
			end++;
		if (start == 1 && end == 1)
			return (1);
		i++;
	}
	return (0);
}
