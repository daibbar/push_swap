#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <limits.h>
# include <stdio.h>



typedef struct s_node{
    struct s_node *next;
    //struct s_node *prevs;
    int index;
    int data;
} s_node;


typedef struct gc_node{
    struct gc_node* next;
    void    *ptr;
} gc_node;


long	ft_atol(const char **nptr);
int     av_parser(s_node *head, int ac, char **av, gc_node **gh);


#endif