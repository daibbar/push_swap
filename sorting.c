/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaibbar <mdaibbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:49:57 by mdaibbar          #+#    #+#             */
/*   Updated: 2026/02/02 22:18:07 by mdaibbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexer(t_stack *list)
{
	t_stack	*temp;

	temp = list;
	while (temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
	while (list)
	{
		temp = list->next;
		while (temp)
		{
			if (temp->data > list->data)
				temp->index += 1;
			else if (temp->data < list->data)
				list->index += 1;
			temp = temp->next;
		}
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

// static t_stack	*mapr(void (*r)(t_stack **), t_stack **sb, t_stack **sa, int *i)
// {
// 	while ((*i) != 0)
// 	{
// 		r(sb);
// 		if (r == rotate)
// 			write(1, "rb\n", 3);
// 		else if (r == reverse_rotate)
// 			write(1, "rrb\n", 4);
// 		(*i)--;
// 	}
// 	p(sa, sb);
// 	write(1, "pa\n", 3);
// 	return (*sb);
// }

// void	push_back(t_stack **stack_a, t_stack **stack_b, int size, int i)
// {
// 	t_stack	*temp;
// 	int		j;

// 	temp = *stack_b;
// 	while (temp)
// 	{
// 		if (temp->index == size - 1 && i < size / 2)
// 		{
// 			temp = mapr(rotate, stack_b, stack_a, &i);
// 			size--;
// 		}
// 		else if (temp->index == size - 1 && i >= size / 2)
// 		{
// 			j = size - i;
// 			temp = mapr(reverse_rotate, stack_b, stack_a, &j);
// 			i = 0;
// 			size--;
// 		}
// 		else
// 		{
// 			i++;
// 			temp = temp->next;
// 		}
// 	}
// }


void	push_back1(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	if (!(*stack_b))
		return ;
	i = get_pos(stack_b, size - 1);
	while (i != size && i > (size / 2))
	{
		reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
		i++;
	}
	while (i != 0 && i <= (size / 2))
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
		i--;
	}
	p(stack_a, stack_b);
	write(1, "pa\n", 3);
	indexer(*stack_a);
	push_back1(stack_a, stack_b, size - 1);
}