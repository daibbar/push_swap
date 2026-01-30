# include "push_swap.h"
// # include <stdio.h>

int ft_sqrt(int nbr)
{
    int i;

    if (nbr == 1)
        return (1);
    if (nbr <= 0)
        return (0);
 
    i = 2;
    while (i <= (nbr / 2))
    {
        if (i * i > nbr)
            return (i - 1);
        if (i * i == nbr)
            return (i);
        i++;
    }
    return (0);
}

void K_distrub(s_node **stack_a, s_node **stack_b)
{
    int size;
    int i;
    int K;

    size = l_size(*stack_a);
    K = (3 * ft_sqrt(size)) / 2;
    i  = 0;
    while (*stack_a)
    {
        if ((*stack_a)->index > i + K)
        {
            rotate(stack_a);
            printf("ra\n");
        }
        else if (((*stack_a)->index) <= (i + K))
        {
            p(stack_b, stack_a);
            printf("pb\n");
            if ((*stack_b)->index <= i)
            {
                rotate(stack_b);
                printf("rb\n");
            }
            i++;
            K++;
        }
        //printf("haniii %d\n", K);
    }
}
