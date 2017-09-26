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
