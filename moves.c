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
    (*head)->next->next = temp1;
    return ;
}


void    ss(s_node **head1, s_node **head2)
{
    swap(head1);
    swap(head2);
}


void    push(s_node **stack, s_node *element)
{
    s_node *temp;

    if (!element)
        return ;
    temp = *stack;
    *stack = element;
    (*stack)->next = temp;
}


void p(s_node **stack_to, s_node **stack_from)
{
    s_node *temp;

    if (!(*stack_from))
        return ;
    temp = *stack_from;
    *stack_from = (*stack_from)->next;
    push(stack_to, temp);
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

void rr(s_node **stack_to, s_node **stack_from)
{
    rotate(stack_to);
    rotate(stack_from);
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

void rrr(s_node **stack_to, s_node **stack_from)
{
    reverse_rotate(stack_to);
    reverse_rotate(stack_from);
}

