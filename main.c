# include "push_swap.h"



static void decide_sort(s_node **stack_a, s_node **stack_b, int size)
{
    int i;

    if (check_sort(*stack_a))
        return ;
    else if (size == 2)
        sort_two(stack_a);
    else 
    {
        indexer(*stack_a);
        if (size == 3) 
            sort_three(stack_a);
        else if (size >= 4 && size <= 15)
            sort_small(stack_a, stack_b, size);
        else
        {
            i = 0;
            k_distrub(stack_a, stack_b);
            push_back(stack_a, stack_b, l_size(*stack_b), i);
        }
    }
    return ;
}

int main(int ac, char **av)
{
    s_node *temp;
	s_node* stack_a;
	gc_node* gh;
    s_node* stack_b;


	if (ac < 2)
		return (0);
    stack_a = NULL;
    stack_b = NULL;
    gh = NULL;
	if (parse_check_av(&stack_a, ac, av, &gh) == 0)
	{
		free_gc(gh);
		return (write(2, "Error\n", 6));
	}
	free_gc(gh);
}