/*
** Finds the median of two sorted arrays.
** Merges both arrays into a new sorted array (like merge step of merge sort).
** Iterates comparing elements from nums1 and nums2.
** After merging, calculates the median:
** - If odd length → middle element
** - If even length → average of two middle elements
**
** Example:
** nums1 = [1, 3], nums2 = [2]
** merged = [1, 2, 3] → median = 2
*/

#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int i;
    int j;
    int k;
    int *array;
    int array_len;
    double  median;

    i = 0;
    j = 0;
    k = 0;
    array_len = nums1Size + nums2Size;
    array = (int *)malloc(array_len * sizeof(int));
    if (!array)
        return (0.0);
    while (i < array_len)
    {
        if (j < nums1Size && k < nums2Size)
        {
            if (nums1[j] < nums2[k])
                array[i] = nums1[j++];
            else
                array[i] = nums2[k++];
        }
        else if (j < nums1Size)
            array[i] = nums1[j++];
        else if (k < nums2Size)
            array[i] = nums2[k++];
        i++;
    }
    if (array_len % 2 == 1)
        median = array[array_len / 2];
    else
        median = ((double)array[array_len / 2 - 1] + array[array_len / 2]) / 2.0;
    free(array);
    return (median);
}
