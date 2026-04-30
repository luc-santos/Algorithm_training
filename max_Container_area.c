int maxArea(int* height, int heightSize) 
{
    int i;
    int j;
    int size;
    int max;
    int aux;

    i = 0;
    j = heightSize - 1;
    aux = 0;
    max = 0;

    while (i < j)
    {
        size = j - i;
        if (height[i] <= height[j])
        {
            aux = size * height[i];
            if (aux > max)
                max = aux;
        }
        else if (height[i] > height[j])
        {
            aux = size * height[j];
            if (aux > max)
                max = aux;
        }
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return (max);
}
