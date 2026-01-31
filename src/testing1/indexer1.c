# include "push_swap.h"


void indexer(s_node *list)
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




void push_back(s_node **stack_a, s_node **stack_b, int size)
{
    s_node *temp;
    s_node *temp1;
    int i;

    temp = *stack_b;
    i = 0;
    while(temp)
    {
        if(temp->index == size - 1 && i <= size / 2)
        {
            while (i != 0)
            {
                rotate(stack_b);
                i--;
            }
            p(stack_a, stack_b);
        }
        
        else if(temp->index == size - 1 && i > size / 2)
        {
            while (i != size)
            {
                reverse_rotate(stack_b);
                i++;
            }
            p(stack_a, stack_b);
        }
        else
        {
            temp = temp->next;
            i++;
        }

    }
}
