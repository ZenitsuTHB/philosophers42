/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:13:00 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/14 16:54:07 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*printf("\nphilo [%i]id_add is [%p] left fork is %p\n", i,
 * (void *)&data->philo[i], (void *)data->philo[i].l_fork);
 * printf("\nphilo [%i]id_add is [%p] right fork is %p\n", i,
 * (void *)&data->philo[i], (void *)data->philo[i].r_fork);
 */

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
			data->philo[i].r_fork = &data->forks[data->phil_num - 1];
		else
			data->philo[i].r_fork = &data->forks[i - 1];
		data->philo[i].l_fork = &data->forks[i % data->phil_num];
	}
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
	{
		data->philo[i].id = i + 1;
		data->philo[i].time_to_die = data->die_time;
		data->philo[i].nb_meal_eat = 0;
		data->philo[i].finished_meal = false;
		data->philo[i].last_time_eat = data->start_time;
		data->philo[i].r_fork = NULL;
		data->philo[i].l_fork = NULL;
		pthread_mutex_init(&data->philo[i].last_teat, NULL);
		data->philo[i].data = data;
		i++;
	}
}

static	int	allocation(t_data *d)
{
	d->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * d->phil_num);
	if (!d->forks)
		return (ft_exit(d, "allocation forks failed !"));
	d->philo = (t_philo *)malloc(sizeof(t_philo) * d->phil_num);
	if (!d->philo)
		return (ft_exit(d, "allocation philo failed !"));
	return (0);
}

int	init_struct(t_data *data, char **argv)
{
	data->phil_num = ft_atol(argv[1]);
	data->die_time = ft_atol(argv[2]);
	data->eat_time = ft_atol(argv[3]);
	data->sleep_time = ft_atol(argv[4]);
	data->meal_num = -1;
	if (argv[5])
		data->meal_num = ft_atol(argv[5]);
	data->start_time = ft_gettime();
	data->finished = false;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->fin_mtx, NULL);
	pthread_mutex_init(&data->fin_meal_mtx, NULL);
	pthread_mutex_init(&data->time_mtx, NULL);
	if (allocation(data) == 1)
		return (0);
	return (1);
}
