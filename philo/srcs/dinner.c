/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 03:33:22 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/14 18:12:18 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *philo_ptr)
{
	int	i;
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	pthread_mutex_lock(&philo->lock);
	philo->time_to_die = get_time() + philo->data->die_time;
	pthread_mutex_unlock(&philo->lock);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time);
	while (philo->data->died == 0)
	{
		repeat_food(philo);
		if (philo->full == philo->data->meal_num && philo->data->mealnum == -1)
			break ;
	}
	return (NULL);
}

int	start_dinner(t_data *data)
{
	int i;

	i = -1;
	data->start_time = get_time();
	while(++i < data->phil_num)
	{
		pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]);
		ft_usleep(1);
	}
	if (pthread_create(&tester, NULL, &supervisor, data) != 0)
		return (0);
	i = -1;
	while(++i < data->phil_num)
		pthread_join(data->tid[i], NULL);
	pthread_join(&data->tester, NULL);
	return (1);
}
