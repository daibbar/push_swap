# include "push_swap.h"


int main(int ac, char **av)
{
    s_node *temp;
	s_node* stack_a = NULL;
	gc_node* gh = NULL;
    s_node* stack_b = NULL;
	if (ac < 2)
		return (0);
	if (parse_check_av(&stack_a, ac, av, &gh) == 0)
	{
		free_gc(gh);
		return (write(2, "Error\n", 6));
	}
    indexer(stack_a);
    k_distrub(&stack_a, &stack_b);
    push_back(&stack_a, &stack_b, l_size(stack_b));
    //push_back1(&stack_a, &stack_b);

    //p(&stack_a, &stack_b);
    temp = stack_a;
    while (temp)
    {
        printf("%d ", temp->data);
		//printf("%d,", stack_a->data);
        temp = temp->next;
    }
    printf("NULL\n");
   // printf("(%d,%d) ", stack_a->data, stack_a->index);
    

	free_gc(gh);
}