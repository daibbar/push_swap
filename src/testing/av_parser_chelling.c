
// int parser_check_av_v1(s_node **head, int ac, char **av, gc_node **gh)
// {
// 	int	i;
//     int sign;
//     long test;

// 	i = 1;
// 	while (i < ac)
//     {
//         if (*av[i] == 0 || *skip_space(av[i]) == 0)
// 			return (0);
// 		while(*av[i])
//     	{
//             av[i] = skip_spc_check_sign((const char*)(av[i]), &sign);
//             if (!(is_digit(*av[i]) || *av[i] == 0))
//                 return (0);
//             else if (*av[i] == 0)
//                 break;
//             test = c_atoi(av[i]);
// 			if (test == (long)INT_MAX + 1 || !(*av[i] == ' ' || *av[i] == 0))
// 				return(0);
// 		//start of allocation
// 			if (nbr_exist_in_stack(*head, (int)test))
// 				return (0);
// 			*head = add_end(*head, (int)test, gh);
// 			if (!(*head))
// 				return (0);
// 		}
// 		i++;
//     }
// 	return (1);
// }