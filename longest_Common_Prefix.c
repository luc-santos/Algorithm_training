char* longestCommonPrefix(char** strs, int strsSize) 
{
    int i;
    int j;
    char *base;

    if (strsSize == 0)
        return ("");
    base = strs[0];
    i = 0;
    while (base[i])
    {
        j = 1;
        while (j < strsSize)
        {
            if (strs[j][i] != base[i])
            {
                base[i] = '\0';
                return (base);
            }
            j++;
        }
        i++;
    }
    return (base);
}
