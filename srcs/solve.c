/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:24:34 by mavagner          #+#    #+#             */
/*   Updated: 2017/10/01 09:28:21 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				min_distance(int *dist, int *spt, int max)
{
	int			min;
	int			index;
	int			sommet;

	min = INT_MAX;
	sommet = -1;
	while (++sommet < max)
	{
		if (spt[sommet] == 0 && dist[sommet] <= min)
		{
			min = dist[sommet];
			index = sommet;
		}
	}
	return (index);
}

void			dijkstra(t_anthill *anthill, int *dist, int *spt, int *path)
{
	int			i;
	int			j;
	int			u;

	i = -1;
	while (++i < anthill->n_rooms - 1)
	{
		u = min_distance(dist, spt, anthill->n_rooms);
		if (u == anthill->end_room)
			break ;
		spt[u] = 1;
		j = -1;
		while (++j < anthill->n_rooms)
		{
			if (!spt[j] && anthill->links[u][j] && dist[u] != INT_MAX &&
				dist[u] + anthill->links[u][j] < dist[j])
			{
				dist[j] = dist[u] + anthill->links[u][j];
				path[j] = u;
			}
		}
	}
	if (dist[anthill->end_room] == INT_MAX)
		ft_error(anthill);
}

void			solve(t_anthill *anthill, int ant_no, int check)
{
	int			dist[anthill->n_rooms];
	int			spt[anthill->n_rooms];
	int			path[anthill->n_rooms];
	int			i;

	i = -1;
	while (++i < anthill->n_rooms)
	{
		dist[i] = INT_MAX;
		spt[i] = 0;
		path[i] = -1;
	}
	dist[anthill->ants[ant_no]] = 0;
	dijkstra(anthill, dist, spt, path);
	if (check)
		print_path(anthill, ant_no, path, anthill->end_room);
}
