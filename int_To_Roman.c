#include <stdlib.h>

char	*intToRoman(int num)
{
	int			values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char		*symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	char		*result;
	int			i;
	int			j;
	int			k;

	result = malloc(16);
	if (!result)
		return (NULL);
	i = 0;
	k = 0;
	while (i < 13)
	{
		while (num >= values[i])
		{
			j = 0;
			while (symbols[i][j])
				result[k++] = symbols[i][j++];
			num -= values[i];
		}
		i++;
	}
	result[k] = '\0';
	return (result);
}
