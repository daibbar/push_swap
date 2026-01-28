// # include "push_swap.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

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

int av_parser(int ac, char **av)
{
	int	i;

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
			// check if *av[i] is not = 0 because atol returns 0 if it finds EOS, to not let it be
			// added to stack ( 0 zayda)
			if (*av[i] == 0 && test == 0) // && test ==0 to check also the the nbr by atol is 0 if not 
			// you will have errors like this one "1        4" give only 1
				break;
			printf("%ld\n", test);
		// start of allocation
		// 	head = add_end(head, (int)test, gh);
		// 	if (!head)
		// 		return (0);
		}
		i++;
    }
	return (1);
}


int main(int ac, char **av)
{
    if (av_parser(ac, av) == 0 || ac == 1)
        return (write(2, "Error\n", 6));
    else 
        return (write(2, "OK\n", 3));
    
}
