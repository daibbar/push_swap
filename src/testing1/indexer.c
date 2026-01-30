# include "push_swap.h"



void ft_insertion_sort(int *arr_copy, int size)
{
    int temp;
    int i;
    int j;

    if (!arr_copy || (size <= 1))
        return ;
    i = 1;
    while (i < size)
    {
        temp = arr_copy[i]; 
        j = i - 1;
        while (arr_copy[j] > temp && j != -1)
        {
            arr_copy[j + 1] = arr_copy[j];
            j--; 
        }
        arr_copy[j + 1] = temp;
        i++;
    }
}

int ft_bin_srch(int *arr, int element, int size)
{
    int index;

    index = size / 2;
    if (element > arr[size / 2])
    {
        index += ft_bin_srch(arr + (size / 2) + 1, element, size - (size / 2) - 1) + 1;
        return index;
    }
    else if (element < arr[size / 2])
    {
        index = ft_bin_srch(arr, element, size - (size / 2) - 1);
        return index;
    }

    else
        return index;
}

s_node *index_stack(s_node *stack)
{
    s_node *temp;
    int *arr_copy;
    int size;
    int i;

    if (!stack)
        return NULL;
    size = l_size(stack);
    arr_copy = (int *)malloc(sizeof(int) * size);
    if (!arr_copy)
        return NULL;
    temp = stack;
    i = 0;
    while(temp)
    {
        arr_copy[i++] = temp->data;
        temp = temp->next;
    }
    ft_insertion_sort(arr_copy, size);
    temp = stack;
    while (temp)
    {
        temp->index = ft_bin_srch(arr_copy, temp->data, size);
        temp = temp->next;
    }
    free(arr_copy);
    arr_copy = NULL;
    return stack;
}