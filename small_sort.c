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

int get_pos(s_node **stack_a, int index)
{
    int i;
    s_node *temp;

    temp = *stack_a;
    i = 0;
    while (temp->next && temp->index != index)
    {
        temp = temp->next;
        i++;
    }
    return (i);  
}

void    sort_three(s_node **stack_a)
{
    int i;

    i = get_pos(stack_a, 2);
    if (i == 1)
    {
        reverse_rotate(stack_a);
        write(1, "rra\n", 4);
    }
    else if (i == 0)
    {
        rotate(stack_a);
        write(1, "ra\n", 3);
    }
    sort_two(stack_a);
}

void    sort_four(s_node **stack_a, s_node **stack_b)
{
    int i;

    i = get_pos(stack_a, 0);
    while (i != 4 && i >= 2)
    {
        reverse_rotate(stack_a);
        write(1, "rra\n", 4);
        i++;
    }
    while (i != 0 && i <= 1)
    {
        rotate(stack_a);
        write(1, "ra\n", 3);
        i--;
    }
    p(stack_b, stack_a);
    write(1, "pb\n", 3);
    indexer(*stack_a);
    sort_three(stack_a);
    p(stack_a, stack_b);
    write(1, "pa\n", 3);
}


void    sort_five(s_node **stack_a, s_node **stack_b)
{
    int i;

    i = get_pos(stack_a, 0);
    while (i != 5 && i >= 3)
    {
        reverse_rotate(stack_a);
        write(1, "rra\n", 4);
        i++;
    }
    while (i != 0 && i <= 2)
    {
        rotate(stack_a);
        write(1, "ra\n", 3);
        i--;
    }
    p(stack_b, stack_a);
    write(1, "pb\n", 3);
    indexer(*stack_a);
    sort_four(stack_a, stack_b);
    p(stack_a, stack_b);
    write(1, "pa\n", 3);
}
