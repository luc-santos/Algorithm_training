/*
** Finds two indices in the array whose values sum to target.
** Uses a brute-force approach with two nested loops.
** Checks every pair of elements until a match is found.
** Returns a dynamically allocated array with the indices.
** Returns NULL if no valid pair exists.
**
** Example:
** array = [2, 7, 11, 15], target = 9 → [0, 1]
*/

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
