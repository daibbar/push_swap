/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaibbar <mdaibbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:50:09 by mdaibbar          #+#    #+#             */
/*   Updated: 2026/02/02 18:44:59 by mdaibbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*alloc_save_t_stack(size_t alloc_size, t_gar **gh)
{
	t_stack	*res;
	t_gar	*stack;

	res = (t_stack *)malloc(alloc_size);
	if (!res)
		return (NULL);
	stack = *gh;
	*gh = malloc(sizeof(t_gar));
	if (!(*gh))
		return (NULL);
	(*gh)->next = stack;
	(*gh)->ptr = res;
	return (res);
}

t_stack	*add_end(t_stack *head, int number, t_gar **gh)
{
	t_stack	*node;

	node = alloc_save_t_stack(sizeof(t_stack), gh);
	if (!node)
		return (NULL);
	node->data = number;
	push(&head, node);
	rotate(&head);
	return (head);
}

int	free_gc(t_gar *gh)
{
	t_gar	*temp;

	temp = gh;
	if (!temp)
		return (0);
	while (temp)
	{
		free(temp->ptr);
		temp = temp->next;
	}
	while (gh)
	{
		temp = gh;
		gh = gh->next;
		free(temp);
	}
	return (0);
}

int	nbr_exist_in_stack(t_stack *head, int nbr)
{
	while (head)
	{
		if (head->data == nbr)
			return (1);
		head = head->next;
	}
	return (0);
}

int	l_size(t_stack *list)
{
	int		size;
	t_stack	*temp;

	temp = list;
	size = 0;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
