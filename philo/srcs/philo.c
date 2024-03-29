/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:29:08 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/14 17:39:39 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_clear(t_data	*data)
{
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
	return (0);
}

int	check_num(char *s, int i)
{
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (!isdigit_space(s[i], 'd'))
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
			if (ft_atol(av[i]) < 1 || ft_atol(av[i]) > INT_MAX)
				return (0);
			rval = check_num(av[i], 0);
			i++;
		}
	}
	return (rval);
}

static int	single_philo(t_data *data)
{
	data->start_time = ft_gettime();
	display_status(FORK, "has taken 1st fork", data->philo);
	spin_lock(data->die_time);
	display_status(DIED, "is dead", data->philo);
	if (ft_exit(data, C"end of simulation") == 1)
		ft_clear(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) != 0)
	{
		if (init_struct(&data, argv) == 0)
			return (1);
		init_philos(&data);
		init_the_forks(&data);
		if (data.phil_num == 1)
			if (single_philo(&data) == 1)
				return (1);
		if (!start_dinner(&data))
			return (1);
	}
	else
		printf(R"%s"Y"%s"B"%s%s"F"%s\n"D, AC, BC, CC, DC, EC);
}
