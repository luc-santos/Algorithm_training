#include <stdlib.h>

int	*two_sum (int *array, int target, int len)
{
	int	i;
	int	j;
	int	*result;

	i = 0;
	if (!array || len < 2)
		return (NULL);
	result = (int *)malloc(2 * (sizeof(int)));
	if (!result)
		return (NULL);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] + array[j] == target)
			{
				result[0] = i;
				result[1] = j;
				return (result);
			}
			j++;
		}
		i++;
	}
	free (result);
	return (NULL);
}
