/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaibbar <mdaibbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:49:28 by mdaibbar          #+#    #+#             */
/*   Updated: 2026/02/02 21:41:14 by mdaibbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	struct t_stack	*next;
	int				index;
	int				data;
}					t_stack;

typedef struct t_gar
{
	struct t_gar	*next;
	void			*ptr;
}					t_gar;

int					parse_av(t_stack **head, int ac, char **av, t_gar **gh);
t_stack				*add_end(t_stack *head, int number, t_gar **gh);
int					free_gc(t_gar *gh);
int					nbr_exist_in_stack(t_stack *head, int nbr);
int					l_size(t_stack *list);
void				indexer(t_stack *stack);
void				swap(t_stack **head);
void				ss(t_stack **head1, t_stack **head2);
void				push(t_stack **stack, t_stack *element);
void				p(t_stack **stack_to, t_stack **stack_from);
void				rotate(t_stack **stack);
void				rr(t_stack **stack_to, t_stack **stack_from);
void				reverse_rotate(t_stack **stack);
void				rrr(t_stack **stack_to, t_stack **stack_from);
void				k_distrub(t_stack **stack_a, t_stack **stack_b);
void				push_back(t_stack **stack_a, t_stack **stack_b, int size,
						int i);
int					check_sort(t_stack *stack);
void				sort_two(t_stack **stack_a);
void				sort_three(t_stack **stack_a);
void				sort_small(t_stack **stack_a, t_stack **stack_b, int size);
int					get_pos(t_stack **stack_a, int index);
void	push_back1(t_stack **stack_a, t_stack **stack_b, int size);

#endif