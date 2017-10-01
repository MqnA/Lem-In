/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:25:38 by mavagner          #+#    #+#             */
/*   Updated: 2017/09/30 21:25:39 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	selection_sort(int *arr, int n)
{
	int i;
	int j;
	int min;

	i = -1;
	while (++i < n - 1)
	{
		min = i;
		j = i;
		while (++j < n)
			min = (arr[j] < arr[min]) ? j : min;
		ft_swap(&arr[i], &arr[min]);
	}
}
