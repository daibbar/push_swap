/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaibbar <mdaibbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:49:57 by mdaibbar          #+#    #+#             */
/*   Updated: 2026/02/02 18:29:29 by mdaibbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// # include <stdio.h>

void	indexer(t_stack *list)
{
	t_stack	*temp;
	t_stack	*temp1;
	int		rank;

	temp = list;
	while (temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
	while (list)
	{
		rank = 0;
		temp1 = list->next;
		while (temp1)
		{
			if (temp1->data > list->data)
				temp1->index += 1;
			if (list->data > temp1->data)
				rank++;
			temp1 = temp1->next;
		}
		list->index += rank;
		list = list->next;
	}
}

void	k_distrub(t_stack **stack_a, t_stack **stack_b)
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

static t_stack	*mapr(void (*r)(t_stack **), t_stack **sb, t_stack **sa, int *i)
{
	while ((*i) != 0)
	{
		r(sb);
		if (r == rotate)
			write(1, "rb\n", 3);
		else if (r == reverse_rotate)
			write(1, "rrb\n", 4);
		(*i)--;
	}
	p(sa, sb);
	write(1, "pa\n", 3);
	return (*sb);
}

void	push_back(t_stack **stack_a, t_stack **stack_b, int size, int i)
{
	t_stack	*temp;
	int		j;

	temp = *stack_b;
	while (temp)
	{
		if (temp->index == size - 1 && i < size / 2)
		{
			temp = mapr(rotate, stack_b, stack_a, &i);
			size--;
		}
		else if (temp->index == size - 1 && i >= size / 2)
		{
			j = size - i;
			temp = mapr(reverse_rotate, stack_b, stack_a, &j);
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
