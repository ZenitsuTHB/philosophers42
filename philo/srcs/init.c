/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 23:13:00 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/30 20:20:42 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int allocation(t_data *data)
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
	i = 0;
	while (i < data->phil_num)
	{
		data->philo[i].l_fork = &data->forks[i];  
		data->philo[i].r_fork = &data->forks[(i + 1) % data->phil_num];
		i++;
	}
}
 
void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
	{
		data->philo[i].one_full = false;
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].time_to_die = data->die_time;
		pthread_mutex_init(&data->philo[i].lock, NULL);
		i++;
	}
}

int	init_struct(t_data *data, char **argv)
{
	data->meal_num = F;
	data->one_died = false;
	data->all_full = false;
	data->phil_num = ft_atol(argv[1]);
	data->die_time = ft_atol(argv[2]);
	data->eat_time = ft_atol(argv[3]);
	data->sleep_time = ft_atol(argv[4]);
	data->start_time = ft_gettime();
	if (argv[5])
		data->meal_num = ft_atol(argv[5]);
	pthread_mutex_init(&data->write, NULL);
	if(allocation(data) == F)
		return (0);
	return (1);
}
