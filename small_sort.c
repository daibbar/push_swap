/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaibbar <mdaibbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:49:53 by mdaibbar          #+#    #+#             */
/*   Updated: 2026/02/02 18:29:54 by mdaibbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	while (stack->next)
	{
		if ((stack->next)->data < stack->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->data > ((*stack_a)->next)->data)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
}

int	get_pos(t_stack **stack_a, int index)
{
	int		i;
	t_stack	*temp;

	temp = *stack_a;
	i = 0;
	while (temp->next && temp->index != index)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	sort_three(t_stack **stack_a)
{
	int	i;

	i = get_pos(stack_a, 2);
	if (i == 1)
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	else if (i == 0)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	sort_two(stack_a);
	return ;
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	if (size == 3)
		return (sort_three(stack_a));
	sort_two(stack_a);
	i = get_pos(stack_a, 0);
	while (i != size && i > (size / 2))
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
		i++;
	}
	while (i != 0 && i <= (size / 2))
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
		i--;
	}
	p(stack_b, stack_a);
	write(1, "pb\n", 3);
	indexer(*stack_a);
	sort_small(stack_a, stack_b, size - 1);
	p(stack_a, stack_b);
	write(1, "pa\n", 3);
}
