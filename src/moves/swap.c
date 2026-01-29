# include "push_swap.h"


void   swap(s_node **head)
{
    s_node *temp;
    s_node *temp1;

    if (!(*head) || !((*head)->next))
        return ;

    temp = *head;
    *head = (*head)->next;
    temp1 = (*head)->next;
    (*head)->next = temp;
    temp = temp1;
    return ;
}


void    ss(s_node **head1, s_node **head2)
{
    swap(head1);
    swap(head2);
}


void    push(s_node **a, s_node *b)
{
    s_node *temp;

    if (!(b))
        return ;
    temp = *a;
    *a = b;
    b->next = temp;
    return ;
}

void    rotate(s_node **stack)
{
    s_node *temp;
    s_node *temp1;

    if (!(*stack) || !((*stack)->next))
        return ;
    temp = *stack;
    temp1 = (*stack)->next;
    while ((*stack)->next)
        *stack = (*stack)->next;
    (*stack)->next = temp;
    (*stack)->next->next = NULL;
    *stack = temp1;
}

void rr(s_node **stack_a, s_node **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}


void    reverse_rotate(s_node **stack)
{
    s_node *temp ;
    s_node *temp1;

    if (!(*stack) || !((*stack)->next))
        return ;
    temp = *stack;
    while((*stack)->next->next)
        *stack = (*stack)->next;
    temp1 = (*stack)->next;
    (*stack)->next = NULL;
    *stack = temp1;
    (*stack)->next = temp;
}

void rrr(s_node **stack_a, s_node **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}

