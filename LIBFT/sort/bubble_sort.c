#include "../libft.h"

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n - 1)
	{
		j = -1;
		while (++j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
		}
	}
}
