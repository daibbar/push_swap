# include "push_swap.h"



int l_size(s_node *list)
{
    int size;
    int *list_copy;
    s_node *temp;

    // calculate the lenght of the stack
    temp = list;
    size = 0;
    while(temp)
    {
        temp = temp->next;
        size++;
    }
    return (size);
}

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


s_node *index_stack(s_node *stack, gc_node **gh)
{
    int *arr_copy;
    int i;
    s_node *temp;
    int size;

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
}

// #include <stdio.h>
// int main()
// {
//     int arr[5] = {9, 8 , 7, 6, 5};

//     ft_insertion_sort(arr, 5);
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d", arr[i]);
//     }
//     printf("\n");
// }