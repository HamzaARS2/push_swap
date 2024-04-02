#include "push_swap.h"

int max_index(int *nums, size_t size)
{
    int i;
    int max_index;

    max_index = 0;
    i = 0;
    while (i < size) 
    {
        if (nums[i] > nums[max_index])
            max_index = i;
        i++;
    }
    return (max_index);
}