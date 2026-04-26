#include <stdbool.h>

static int	first_match(char *s, char *p)
{
	if (*s == '\0')
		return (0);
	if (*p == '.')
		return (1);
	return (*s == *p);
}

bool	isMatch(char *s, char *p)
{
	if (*p == '\0')
		return (*s == '\0');

	if (*(p + 1) == '*')
	{
		if (isMatch(s, p + 2))
			return (true);
		if (first_match(s, p) && isMatch(s + 1, p))
			return (true);
		return (false);
	}
	else
	{
		if (first_match(s, p))
			return (isMatch(s + 1, p + 1));
		return (false);
	}
}
