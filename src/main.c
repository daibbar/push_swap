/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaibbar <mdaibbar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:13:12 by mdaibbar          #+#    #+#             */
/*   Updated: 2026/01/25 01:13:15 by mdaibbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <stdio.h>
# include "push_swap.h"


int main(int ac, char **av)
{
	s_node* head = NULL;
	gc_node* gh = NULL;
	if (ac < 2)
		return (0);
	if (av_parser(head, ac, av, &gh) == 0)
	{
		free_gc(gh);
		return (write(2, "Error\n", 6));
	}
	free(gh);
}