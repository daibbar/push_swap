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
    temp = stack_a;
    stack_a = index_stack(stack_a);
    if (!stack_a)
    {
        free_gc(gh);
        return 0;
    }
    while (stack_a)
    {
        printf("|_ %d _ %d| -> ", stack_a->data, stack_a->index);
		//printf("%d,", stack_a->data);
        stack_a = stack_a->next;
    }
    printf("NULL\n");
    stack_a = temp;
    K_distrub(&stack_a, &stack_b);
    while (stack_b)
    {
		//printf("|_ %d _ %d| -> ", stack_a->data, stack_a->index);
		printf("%d ", stack_b->data);
        stack_b = stack_b->next;
    }
    printf("NULL\n");


	free_gc(gh);
}