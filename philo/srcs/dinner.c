/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 03:33:22 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/16 17:51:15 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * checks if the philosopher's ID is even means si es par
 * curtime - utilma < dietime = vivo
 */

static int	check_death(t_data *data, int i)
{
	if (ft_gettime() - data->philo[i].last_time_eat >= get_timedie(data))
	{
		set_finished(data);
		display_status(DIED, "is dead", &data->philo[i]);
		return (EXIT);
	}
	return (0);
}

static void	check_full(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < get_philnum(data))
	{
		pthread_mutex_lock(&data->fin_meal_mtx);
		if (data->philo[i].finished_meal == true)
		{
			pthread_mutex_unlock(&data->fin_meal_mtx);
			count++;
		}
		pthread_mutex_unlock(&data->fin_meal_mtx);
		if (count == get_philnum(data))
			set_finished(data);
		i++;
	}
}

static void	*monitoring(void *arg)
{
	int		i;
	t_data	*data;

	data = (void *)arg;
	while (get_end(data) == false)
	{
		i = 0;
		while (i < get_philnum(data) && get_end(data) == false)
		{
			if (check_death(data, i) == EXIT || get_end(data) == true)
				break ;
			i++;
		}
		check_full(data);
		spin_lock(data->die_time);
	}
	return ((void *)0);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0)
		spin_lock(philo->data->eat_time);
	while (get_end(philo->data) == false)
	{
		take_the_forks(philo);
		eat_your_foods(philo);
		sleep_and_think(philo);
		if (get_end(philo->data) == true)
			break ;
	}
	return (NULL);
}

int	start_dinner(t_data *data)
{
	int		i;

	i = -1;
	data->start_time = ft_gettime();
	while (++i < get_philnum(data))
	{
		data->philo[i].last_time_eat = data->start_time;
		pthread_create(&data->philo[i].t_id, NULL, &routine, &data->philo[i]);
	}
	monitoring(data);
	i = -1;
	while (++i < get_philnum(data))
		pthread_join(data->philo[i].t_id, NULL);
	if (ft_exit(data, C"end of simulation") == 1)
		ft_clear(data);
	return (1);
}
