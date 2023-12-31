/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:59:05 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/31 17:55:54 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * utils
 * ft_isdigit
 * ft_atoi
 */
int	check_num(char *s, int i)
{
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	rval;

	i = 1;
	rval = 1;
	if (ac < 5 || ac > 6)
		return (0);
	else if (ac == 5 || ac == 6)
	{
		while (i < ac)
		{
			if (ft_atol(av[i]) < 1 || ft_atol(av[i]) >  INT_MAX)
				return (0);
			rval = check_num(av[i], 0);
			i++;
		}
	}
	return (rval);
}

void	error_function(void)
{
	printf("%s%s%s", ARG, RAG, GAR);
	return ;
}

int	main(int argc, char **argv)
{
//	t_data	data;

	if (check_args(argc, argv) == 0)
		error_function();
	//init_struct(&data);TODO
	return (0);
}
