/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:13:00 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/09 18:27:24 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*printf("\nphilo [%i]id_add is [%p] left fork is %p\n", i,
 * (void *)&data->philo[i], (void *)data->philo[i].l_fork);
 * printf("\nphilo [%i]id_add is [%p] right fork is %p\n", i,
 * (void *)&data->philo[i], (void *)data->philo[i].r_fork);
 */

static	int	allocation(t_data *data)
{
	data->t_id = malloc(sizeof(pthread_t) * data->phil_num);
	if (!data->t_id)
		return (ft_exit(data, "allocation pthread ID's failed !"));
	data->philo = malloc(sizeof(t_philo) * data->phil_num);
	if (!data->philo)
		return (ft_exit(data, "allocation philo failed !"));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->phil_num);
	if (!data->forks)
		return (ft_exit(data, "allocation forks failed !"));
	return (0);
}

void	init_the_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->phil_num)
		pthread_mutex_init(&data->forks[i], NULL);
	i = -1;
	while (++i < data->phil_num)
	{
		if (i == 0)
			data->philo[i].l_fork = &data->forks[data->phil_num - 1];
		else
			data->philo[i].l_fork = &data->forks[i - 1];
		data->philo[i].r_fork = &data->forks[i % data->phil_num];
	}
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].nb_meal_eat = 0;
		data->philo[i].finished_meal = false;
		data->philo[i].time_to_die = data->die_time;
		data->philo[i].last_time_eat = data->start_time;
		pthread_mutex_init(&data->philo[i].lock, NULL);
		pthread_mutex_init(&data->philo[i].last_teat, NULL);
		i++;
	}
}

int	init_struct(t_data *data, char **argv)
{
	data->meal_num = -1;
	data->phil_num = ft_atol(argv[1]);
	data->die_time = ft_atol(argv[2]);
	data->eat_time = ft_atol(argv[3]);
	data->sleep_time = ft_atol(argv[4]);
	if (argv[5])
		data->meal_num = ft_atol(argv[5]);
	data->start_time = ft_gettime();
	data->finished = false;
	pthread_mutex_init(&data->write, NULL);
	//pthread_mutex_init(&data->fin_mtx, NULL);
	if (allocation(data) == 1)
		return (0);
	return (1);
}
