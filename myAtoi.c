#include <limits.h>

int	myAtoi(char *s)
{
	int	minus;
	int	n;
	int	digit;

	n = 0;
	minus = 0;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			minus++;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		digit = *s - '0';
		if (n > (INT_MAX - digit) / 10)
		{
			if (minus % 2 == 0)
				return (INT_MAX);
			return (INT_MIN);
		}
		n = n * 10 + digit;
		s++;
	}
	if (minus % 2 == 0)
		return (n);
	return (-n);
}
