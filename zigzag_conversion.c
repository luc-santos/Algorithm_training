/*
** Converts a string into a zigzag pattern and reads it row by row.
** Calculates a cycle length based on numRows.
** Iterates each row and picks characters following the zigzag pattern.
** Handles middle rows by adding diagonal elements.
** Builds and returns a new reordered string.
**
** Example:
** s = "PAYPALISHIRING", numRows = 3 → "PAHNAPLSIIGYIR"
*/

char *convert(char *s, int numRows)
{
    int len;
    int cycle;
    int row;
    int i;
    int k;
    int second;
    char *res;

    len = strlen(s);
    if (numRows == 1 || numRows >= len)
        return (strdup(s));

    res = malloc(len + 1);
    if (!res)
        return (NULL);

    cycle = 2 * numRows - 2;
    k = 0;
    row = 0;
    while (row < numRows)
    {
        i = row;
        while (i < len)
        {
            res[k++] = s[i];
            second = i + cycle - 2 * row;
            if (row != 0 && row != numRows - 1 && second < len)
                res[k++] = s[second];
            i += cycle;
        }
        row++;
    }
    res[k] = '\0';
    return (res);
}
