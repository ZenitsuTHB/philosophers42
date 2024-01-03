/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:29:08 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/03 20:54:29 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * utils
 * ft_isdigit
 * ft_atoi
 */
static void	ft_clear(t_data	*data)
{
//	if (data->tid)
//		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
}

int	ft_exit(t_data *data, char *msg)
{
	int	i;
	
	printf("%s", msg);
	if (data)
	{
		i = -1;
		while (++i < data->phil_num)
		{
			pthread_mutex_destroy(&data->forks[i]);
			pthread_mutex_destroy(&data->philo[i].lock);
		}
	//	pthread_mutex_destroy(&data->write);
		pthread_mutex_destroy(&data->lock);
		ft_clear(data);
	}
	return (F);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
	{
		data->philo[i].id = i + 1;
		pthread_mutex_init(&data->philo[i].lock, NULL);
		i++;
	}
}

static int allocation(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->phil_num);
	if (!data->philo)
		return (ft_exit(data, "allocation philo failed !"));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->phil_num);
	if (!data->forks)
		return (ft_exit(data, "allocation forks failed !"));
	return (0);
}

int	init_struct(t_data *data, char **argv)
{
	data->died = F;
	data->meal_num = -1;
	data->phil_num = ft_atol(argv[1]);
	data->die_time = ft_atol(argv[2]);
	data->eat_time = ft_atol(argv[3]);
	data->sleep_time = ft_atol(argv[4]);
	data->start_time = ft_get_time();
	if (argv[5])
		data->meal_num = ft_atol(argv[5]);
	if(allocation(data) == F)
		return (0);
	return (1);
}

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
			if (ft_atol(av[i]) < 1 || ft_atol(av[i]) > INT_MAX)
				return (0);
			rval = check_num(av[i], 0);
			i++;
		}
	}
	return (rval);
}

int	error_function(void)
{
	printf("%s%s%s", ARG, RAG, GAR);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) == 0)
		return (1);
	if (init_struct(&data, argv) == 0)
		return (1);
	printf("\ninit done\n");
	printf("died --> %d\n", data.died);
	init_philos(&data);
	printf("philum-->%ld\nmealnu-->%ld\n", data.phil_num, data.meal_num);
	printf("dietime-->%li\neattime-->%li\n", data.die_time, data.eat_time);
	printf("sleep_time-->%li\nstarttime-->%li\n", data.sleep_time, data.start_time);
	printf("philum-->%ld\nmealnu-->%ld\n", data.phil_num, data.meal_num);
	return (0); 
}
