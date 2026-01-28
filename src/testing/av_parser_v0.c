# include "push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaibbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:32:17 by mdaibbar          #+#    #+#             */
/*   Updated: 2025/10/20 15:32:18 by mdaibbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

long	ft_atol(const char **nptr)
{
	int		sign;
	long	res;
	long	nbr;
	
	sign = 1;
	*nptr = skip_spc_check_sign(*nptr, &sign);
	nbr = 0;
	// **nptr != 0 because there might be a number before like this "  1     "
	if (!(**nptr >= '0' && **nptr <= '9') && **nptr != 0)
		return ((long)INT_MAX + 1);
	while ((**nptr >= '0' && **nptr <= '9'))
	{
		res = nbr;
		nbr = nbr * 10 + **nptr - 48;
		if ((nbr > (long)INT_MAX && sign == 1) || nbr > (long)INT_MAX + 1) 
		// possible that the value is MIN_INT and without the condition it will consider it indefined
			return ((long)INT_MAX + 1);
		(*nptr)++;
	}
	// if the next element is "      1+1"
	if ((**nptr) != ' ' && (**nptr) != 0) 
	 	return ((long)INT_MAX + 1);
	return (sign * nbr);
}

int av_parser(s_node* head, int ac, char **av, gc_node* gh)
{
	int		i;

	i = 1;
	while (i < ac)
    {
        if (*av[i] == 0 || *skip_space(av[i]) == 0)
			return (0);
		while(*av[i])
    	{
        	long test = ft_atol((const char **)&av[i]);
			if (test == (long)INT_MAX + 1)
				return(0);
		//start of allocation
			if (!(*av[i]))
				break ;
			head = add_end(head, (int)test, gh);
			if (!head)
				return (0);
		}
		i++;
    }
	return (1);
}

