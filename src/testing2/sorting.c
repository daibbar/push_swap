# include "push_swap.h"
// # include <stdio.h>


void index_stack(s_node *list)
{
    s_node *temp;
    s_node *temp1;
    int rank;

    temp = list;
    while (temp)
    {
        rank = 0;
        temp1 = temp->next;
        while (temp1)
        {
            if (temp > temp1)
                rank++;
            temp1 = temp1->next;
        }
        temp->index = rank;
        temp = temp->next;
    }
}

int ft_sqrt(int nbr)
{
    int i;

    if (nbr == 1)
        return (1);
    if (nbr <= 0)
        return (0);
 
    i = 2;
    while (i <= (nbr / 2))
    {
        if (i * i > nbr)
            return (i - 1);
        if (i * i == nbr)
            return (i);
        i++;
    }
    return (0);
}

void K_distrub(s_node **stack_a, s_node **stack_b)
{
    int size;
    int i;
    int K;

    size = l_size(*stack_a);
    K = (3 * ft_sqrt(size)) / 2;
    i  = 0;
    while (*stack_a)
    {
        if ((*stack_a)->index > i + K)
        {
            rotate(stack_a);
            printf("ra\n");
        }
        else if (((*stack_a)->index) <= (i + K))
        {
            p(stack_b, stack_a);
            printf("pb\n");
            if ((*stack_b)->index <= i)
            {
                rotate(stack_b);
                printf("rb\n");
            }
            i++;
            K++;
        }
    }
}



void push_back(s_node **stack_a, s_node **stack_b, int size)
{
    s_node *temp;
    s_node *temp1;
    int i;

    temp = *stack_b;
    i = 1;
    while(temp)
    {
        if(temp->index == size - 1 && i < size / 2)
        {
            while (i != 1)
            {
                rotate(stack_b);
                i--;
            }
            p(stack_a, stack_b);
            temp = *stack_b;
            size--;
            //break ;
            //printf("%d", size);
        }
        
        else if(temp->index == size - 1 && i >= size / 2)
        {
            while (i != size)
            {
                reverse_rotate(stack_b);
                i++;
            }
            p(stack_a, stack_b);
            temp = *stack_b;
            size--;
        }
        else
        {
            temp = temp->next;
            i++;
        }

    }
}