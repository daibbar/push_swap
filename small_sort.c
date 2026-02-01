# include "push_swap.h"

int check_sort(s_node *stack)
{
    while (stack->next)
    {
        if ((stack->next)->data < stack->data)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void sort_two(s_node **stack_a)
{
    if ((*stack_a)->data > ((*stack_a)->next)->data)
    {
        swap(stack_a);
        write(1, "sa\n", 3);
    }
}

void    sort_three(s_node **stack_a)
{
    int i;
    s_node *temp;

    temp = *stack_a;
    i = 0;
    while (temp->index != 2)
    {
        temp = temp->next;
        i++;
    }
    if (i == 1)
    {
        reverse_rotate(stack_a);
        write(1, "rra\n", 4);
        sort_two(stack_a);
    }
    else if (i == 0)
    {
        rotate(stack_a);
        write(1, "ra\n", 3);
        sort_two(stack_a);
    }
    else
        sort_two(stack_a);
}

void    sort_four(s_node **stack_a)
{
    int i;
    s_node *temp;

    temp = *stack_a;
    i = 0;
    while (temp->index != size   - 1)
    {
        temp = temp->next;
        i++;
    }
    if(i == 2)
    {
        reverse_rotate(stack_a);
        write(1, "rra\n", 4);
    }
    while (i != 0)
    {
        rotate(stack_a);
        write(1, "ra\n", 3);
        i--;
    }
    sort

}
