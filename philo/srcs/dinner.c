/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 03:33:22 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/08 20:21:20 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * checks if the philosopher's ID is even means si es par
 * curtime - utilma < dietime = vivo
 */

static void	check_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->write);
	if (ft_gettime() - data->philo[i].last_time_eat >= data->die_time)
	{
		pthread_mutex_unlock(&data->write);
		data->finished = true;
		display_status(DIED, "is dead", &data->philo[i]);
	}
	pthread_mutex_unlock(&data->write);
}

static void	check_full(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->phil_num)
	{
		if (data->philo[i].finished_meal == true)
			count++;
		if (count == data->phil_num)
			data->finished = true;
		i++;
	}
}

static void	*monitoring(void *arg)
{
	int		i;
	t_data	*data;

	data = (void *)arg;
	while (data->finished == false)
	{
		i = 0;
		while (i < data->phil_num)
			check_death(data, i++);
		check_full(data);
		usleep(10);
	}
	return ((void *)0);
}

static void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0)
		spin_lock(philo->data->eat_time);
	while (philo->finished_meal == false)
	{
		take_the_forks(philo);
		eat_your_foods(philo);
		sleep_and_think(philo);
		if (philo->data->finished == true)
			break ;
	}
	return (NULL);
}

int	start_dinner(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = ft_gettime();
	while (++i < data->phil_num)
	{
		pthread_mutex_lock(&data->philo->last_teat);
		data->philo[i].last_time_eat = data->start_time;
		pthread_mutex_unlock(&data->philo->last_teat);
		pthread_create(&data->t_id[i], NULL, &routine, &data->philo[i]);
		usleep(1);
	}
	monitoring(data);
	while (++i < data->phil_num)
		pthread_join(data->t_id[i], NULL);
	if (ft_exit(data, C"end of simulation") == 1)
		ft_clear(data);
	return (1);
}
