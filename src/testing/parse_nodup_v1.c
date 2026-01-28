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
int	ft_isdigit(int ch)
{
	if ((ch >= '0' && ch <= '9'))
		return (1);
	else
		return (0);
}
static char	*skip_space(const char *str)
{
	while (*str == ' ')
		str++;
	return ((char*)str);
}
static char	*skip_spc_check_sign(const char *nptr, int *sign)
{
	nptr = skip_space(nptr);
	if ((*nptr == '-' || *nptr == '+') && ft_isdigit(*(nptr + 1)))
	{
		if (*nptr == '-')
	    	*sign *= -1;
	    nptr++;
    }
	return ((char *)nptr);
}

long	custom_atoi(const char **nptr)
{
	int		sign;
	long	res;
	long	nbr;
	
	sign = 1;
	*nptr = skip_spc_check_sign(*nptr, &sign);
	nbr = 0;
	if (!is_digit(**nptr) && **nptr != 0)
		return ((long)INT_MAX + 1);
	while ((**nptr >= '0' && **nptr <= '9'))
	{
		res = nbr;
		nbr = nbr * 10 + **nptr - 48;
		if ((nbr > (long)INT_MAX && sign == 1) || nbr > (long)INT_MAX + 1) 
			return ((long)INT_MAX + 1);
		(*nptr)++;
	}
	if (!((**nptr) == ' ' || (**nptr) == 0)) 
	 	return ((long)INT_MAX + 1);
	return (sign * nbr);
}

static s_node    *alloc_save_s_node(size_t alloc_size, gc_node **gh)
{
    s_node *res;
    gc_node *stack;

    res = (s_node*)malloc(alloc_size);
    if (!res)
        return NULL;

    
    stack = *gh; 
    *gh = malloc(sizeof(gc_node));
    if (!(*gh))
        return NULL;
    (*gh)->next = stack; 
    (*gh)->ptr = res; 
    return res;
}
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

int nbr_exist_in_stack(s_node *head, int nbr)
{
    while (head)
    {
        if (head->data == nbr)
            return (1);
        head = head->next;
    }
    return (0);
}
int parse_check_av(s_node **head, int ac, char **av, gc_node **gh)
{
	int	i;
    long test;

	i = 1;
	while (i < ac)
    {
        if (*av[i] == 0 || *skip_space(av[i]) == 0)
			return (0);
		while(*av[i])
    	{
        	test = custom_atoi((const char **)&av[i]);
			if (test == (long)INT_MAX + 1)
				return(0);
			if (*av[i] == 0 && test == 0 && *(av[i] - 1) == ' ')
			    break ;
			if (nbr_exist_in_stack(*head, (int)test))
				return (0);
			*head = add_end(*head, (int)test, gh);
			if (!(*head))
				return (0);
		}
		i++;
    }
	return (1);
}



int main(int ac, char **av)
{
	s_node* head = NULL;
	gc_node* gh = NULL;
	if (ac < 2)
		return (0);
	if (parse_check_av(&head, ac, av, &gh) == 0)
	{
		free_gc(gh);
		return (write(2, "Error\n", 6));
	}
    while (head)
    {
		printf("|_ %d _| -> ", head->data);
        head = head->next;
    }
	printf("NULL\n");
	free_gc(gh);
}