# include "push_swap.h"
// # include <stdio.h>

void indexer(s_node *list)
{
    s_node *temp;
    s_node *temp1;
    int rank;

    temp = list;
    temp->index = 0;
    while (temp)
    {
        rank = 0;
        temp1 = temp->next;
        while (temp1)
        {
            if (temp1->data > temp->data)
                temp1->index += 1;
            if (temp->data > temp1->data)
                rank++;
            temp1 = temp1->next;
        }
        temp->index += rank;
        temp = temp->next;
    }
}

void	k_distrub(s_node **stack_a, s_node **stack_b)
{
	int	size;
	int	i;
	int	k;

	size = l_size(*stack_a);
	k = (size / 20) + 7;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index > i + k)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
		else if ((*stack_a)->index <= (i + k))
		{
			p(stack_b, stack_a);
			write(1, "pb\n", 3);
			if ((*stack_b)->index <= i++)
			{
				rotate(stack_b);
				write(1, "rb\n", 3);
			}
		}
	}
}

static s_node	*maprot(void (*rot)(s_node **), s_node **sb, s_node **sa, int *i)
{
    while ((*i) != 0)
     {
        rot(sb);
        if (rot == rotate)
            write(1, "rb\n", 3);
        else if (rot == reverse_rotate)
            write(1, "rrb\n", 4);
        (*i)--;
    }
    p(sa, sb);
    write(1, "pa\n", 3);    
    return *sb;
}

void push_back(s_node **stack_a, s_node **stack_b, int size, int i)
{
    s_node *temp;
    int j;
    
    temp = *stack_b;
    while(temp)
    {
        if(temp->index == size - 1 && i < size / 2)
        {    
            temp = maprot(rotate, stack_b, stack_a, &i);
            size--;
        }
        else if (temp->index == size - 1 && i >= size / 2)
        {
            j = size - i;
            temp = maprot(reverse_rotate, stack_b, stack_a, &j);
            i = 0;
            size--;
        }
        else
        {
            i++;
            temp = temp->next; 
        }
    }
}
