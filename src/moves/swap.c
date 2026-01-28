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

