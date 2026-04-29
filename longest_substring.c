/*
** Finds the length of the longest substring without repeating characters.
** For each position, expands forward until a duplicate is found.
** Uses an array to track already seen characters.
** Resets tracking for each new starting position.
** Keeps the maximum length found.
**
** Example:
** s = "abcabcbb" → 3 ("abc")
*/

#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int i;
    int j;
    int len;
    int max_len;
    int char_counter[256] = {0};

    i = 0;
    max_len = 0;
    while (s[i])
    {
        j = i;
        len = 0;
        memset(char_counter, 0, sizeof(char_counter));
        while (s[j])
        {
            if (char_counter[(unsigned char)s[j]] == 0)
            {
                char_counter[(unsigned char)s[j]] = 1;
                len++;
            }
            else
                break;
            if (len > max_len)
                max_len = len;
            j++;
        }
        i++;
    }
    return (max_len);
}
