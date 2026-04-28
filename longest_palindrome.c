/*
** Finds the longest palindromic substring inside a string.
** Expands from each character as the center of a palindrome.
** Checks both odd and even length palindromes.
** Keeps the start position and max length found.
** Allocates and returns a new string with the result.
**
** Example:
** s = "babad" → "bab" or "aba"
*/

#include <stdlib.h>
#include <string.h>

char    *longestPalindrome(char *s)
{
    int        i;
    int        left;
    int        right;
    int        len;
    int        max_len;
    int        start;
    int        s_len;
    char    *final_s;

    i = 0;
    start = 0;
    max_len = 1;
    s_len = strlen(s);

    while (i < s_len)
    {
        left = i;
        right = i;
        while (left >= 0 && right < s_len && s[left] == s[right])
        {
            left--;
            right++;
        }
        len = right - left - 1;
        if (len > max_len)
        {
            start = left + 1;
            max_len = len;
        }
        
        left = i;
        right = i + 1;
        while (left >= 0 && right < s_len && s[left] == s[right])
        {
            left--;
            right++;
        }
        len = right - left - 1;
        if (len > max_len)
        {
            start = left + 1;
            max_len = len;
        }
        i++;
    }

    final_s = (char *)malloc(max_len + 1);
    if (!final_s)
        return (NULL);
    strncpy(final_s, &s[start], max_len);
    final_s[max_len] = '\0';
    return (final_s);
}
