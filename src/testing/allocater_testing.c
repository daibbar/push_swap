# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>


typedef struct s_node{
    struct s_node *next;
    //struct s_node *prevs;
    int data;
} s_node;

typedef struct gc_node{
    struct gc_node* next;
    s_node    *ptr;
} gc_node;



static s_node    *alloc_save_s_node(size_t alloc_size, gc_node **gh)
{
    s_node *res;
    gc_node *stack;

    res = (s_node*)malloc(alloc_size); //allocated space for stack node
    if (!res)
        return NULL;

    // save in the list of gc
    stack = *gh; //save the stack 
    *gh = malloc(sizeof(gc_node)); // make the head points to a new node
    if (!(*gh))
        return NULL;
    (*gh)->next = stack; // the new node points on the stack
    (*gh)->ptr = res; // save the the s_code
    return res;
}

//return s_node* to return the head of the stack to check if any error has occured
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


int main(int ac, char **av)
{

    s_node *head = NULL;
    gc_node *gh = NULL;
    head = add_end(head, 15, &gh);
    if (!head)
        printf("shiiiit0000000");
    head = add_end(head, 25, &gh);
    // if (!head)
    //     printf("ara wkan");
    if (gh == NULL)
        printf("shiiiito");
    gc_node* stack = gh;
    while (head)
    {
        printf("%d\n", head->data);
        // gh = gh->next;
        head = head->next;
    }
    return (0);

}