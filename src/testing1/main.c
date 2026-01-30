# include "push_swap.h"

int main(int ac, char **av)
{
    s_node *temp;
	s_node* head = NULL;
	gc_node* gh = NULL;
	if (ac < 2)
		return (0);
	if (parse_check_av(&head, ac, av, &gh) == 0)
	{
		free_gc(gh);
		return (write(2, "Error\n", 6));
	}
    temp = head;
    while (head)
    {
		printf("|_ %d _| -> ", head->data);
        head = head->next;
    }
	printf("NULL\n");
    head = temp;
    printf("the size of the stack is : %d", l_size(head));
    head = index_stack(head);
    // reverse_rotate(&head);
     while (head)
    {
		printf("|_ %d _ %d| -> ", head->data, head->index);
        head = head->next;
    }
	printf("NULL\n");

	free_gc(gh);
    system("leaks push_swap");
}