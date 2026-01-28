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

void    *allocate_save(size_t alloc_size, gc_node **gh)
{
    void *res;
    gc_node *temp;

    res = malloc(alloc_size); //allocated space for stack node
    if (!res)
        return NULL;

    // save in the list of gc
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
    s_node* temp;

    temp = head;
    if (!temp)
    {    
        temp = (s_node* )allocate_save(sizeof(s_node), gh);
        if(!temp)
            return NULL;
        temp->next = NULL;
        temp->data = number;
    }
    else
    {
        while (temp->next)
            temp = temp->next;
        temp->next = (s_node* )allocate_save(sizeof(s_node), gh);
        if (!(temp->next))
            return NULL;
        temp->next->next = NULL;
        temp->next->data = number;
    }
    return (head);
}
// 1 2 3 " "  