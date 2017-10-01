/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:25:28 by mavagner          #+#    #+#             */
/*   Updated: 2017/09/30 21:25:28 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	build_heap(int *arr, int n, int i)
{
	int largest;
	int l;
	int r;

	largest = i;
	l = (2 * i) + 1;
	r = (2 * i) + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		ft_swap(&arr[i], &arr[largest]);
		build_heap(arr, n, largest);
	}
}

void		heap_sort(int *arr, int n)
{
	int i;

	i = (n / 2) - 1;
	while (i >= 0)
	{
		build_heap(arr, n, i);
		i--;
	}
	i = n - 1;
	while (i >= 0)
	{
		ft_swap(&arr[0], &arr[i]);
		build_heap(arr, i, 0);
		i--;
	}
}
