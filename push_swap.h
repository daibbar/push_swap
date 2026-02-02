#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>



typedef struct s_node{
    struct s_node *next;
    int index;
    int data;
} s_node;


typedef struct gc_node{
    struct gc_node* next;
    void    *ptr;
} gc_node;


int parse_check_av(s_node **head, int ac, char **av, gc_node **gh);
s_node *add_end(s_node *head, int number, gc_node **gh);
int    free_gc(gc_node *gh);
int nbr_exist_in_stack(s_node *head, int nbr);
int l_size(s_node *list);
void  indexer(s_node *stack);
void   swap(s_node **head);
void    ss(s_node **head1, s_node **head2);
void    push(s_node **stack, s_node *element);
void p(s_node **stack_to, s_node **stack_from);
void    rotate(s_node **stack);
void rr(s_node **stack_to, s_node **stack_from);
void    reverse_rotate(s_node **stack);
void rrr(s_node **stack_to, s_node **stack_from);
void k_distrub(s_node **stack_a, s_node **stack_b);
void push_back(s_node **stack_a, s_node **stack_b, int size, int i);
int check_sort(s_node *stack);
void    sort_two(s_node **stack_a);
void    sort_three(s_node **stack_a);
void    sort_small(s_node **stack_a, s_node **stack_b, int size);



#endif