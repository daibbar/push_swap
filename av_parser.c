/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaibbar <mdaibbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:50:24 by mdaibbar          #+#    #+#             */
/*   Updated: 2026/02/03 11:34:15 by mdaibbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int ch)
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
	return ((char *)str);
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

static long	error_atoi(const char **nptr)
{
	int		sign;
	long	res;
	long	nbr;

	sign = 1;
	*nptr = skip_spc_check_sign(*nptr, &sign);
	nbr = 0;
	if (!ft_isdigit(**nptr) && **nptr != 0)
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

int	parse_av(t_stack **head, int ac, char **av, t_gar **gh)
{
	int		i;
	long	test;

	i = 1;
	while (i < ac)
	{
		if (*av[i] == 0 || *skip_space(av[i]) == 0)
			return (0);
		while (*av[i])
		{
			test = error_atoi((const char **)&av[i]);
			if (test == (long)INT_MAX + 1)
				return (0);
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
