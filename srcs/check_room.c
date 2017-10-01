/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:24:03 by mavagner          #+#    #+#             */
/*   Updated: 2017/09/30 21:24:05 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				check_room(t_anthill *anthill, char *line)
{
	int			i;
	char		**lines;

	i = 0;
	lines = ft_strsplit(line, ' ');
	while (lines[i])
		i++;
	if (i != 3 || lines[0][0] == 'L' ||
		!is_digit(lines[1]) || !is_digit(lines[2]))
		ft_error(anthill);
	return (1);
}
