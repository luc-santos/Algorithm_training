/*
** Implements regex matching with support for '.' and '*'.
** '.' matches any single character.
** '*' means zero or more of the previous character.
** Uses recursion to check all valid matching possibilities.
** Handles two cases:
** - Skip "x*" (zero occurrences)
** - Use "x*" if first characters match
**
** Example:
** s = "aab", p = "c*a*b" → true
*/

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
