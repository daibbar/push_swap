# include "push_swap.h"

void free_gc(gc_node *gh)
{
    gc_node *temp;

    temp = gh;
    if (!temp)
        return ;
    while(temp)
    {
        free(temp->ptr);
        temp = temp->next;
    }
    while(gh)
    {
        temp = gh;
        gh = gh->next;
        free(temp);
    }
}
int nbr_exist_in_stack(s_node *head, int nbr)
{
    while (head)
    {
        if (head->data == nbr)
            return (1);
        head = head->next;
    }
    return (0);
}

// gc_node *save_ptr(void *ptr, gc_node **gh)
// {
//     gc_node *stack;

//     stack = *gh; 
//     *gh = malloc(sizeof(gc_node));
//     if (!(*gh))
//         return NULL;
//     (*gh)->next = stack; 
//     (*gh)->ptr = ptr; 
//     return (*gh);
// }

static s_node    *alloc_save_s_node(size_t alloc_size, gc_node **gh)
{
    s_node *res;
    gc_node *temp;

    res = (s_node*)malloc(alloc_size);
    if (!res)
        return NULL;

    temp = *gh; 
    *gh = malloc(sizeof(gc_node));
    if (!(*gh))
        return NULL;
    (*gh)->next = temp; 
    (*gh)->ptr = res; 
    return res;
}

s_node *add_end(s_node *head, int number, gc_node **gh) 
{
    s_node* stack;

    stack = head;
    if (!stack)
    {    
        stack = alloc_save_s_node(sizeof(s_node), gh);
        if(!stack)
            return NULL;
        head = stack;
        stack->next = NULL;
        stack->data = number;
    }
    else
    {
        while (stack->next)
            stack = stack->next;
        stack->next = alloc_save_s_node(sizeof(s_node), gh);
        if (!(stack->next))
            return NULL;
        stack->next->next = NULL;
        stack->next->data = number;
    }
    return (head);
}