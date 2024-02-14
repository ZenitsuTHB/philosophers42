/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:52:53 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/14 16:36:31 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	get_philnum(t_data *data)
{
	int	phil_num;

	pthread_mutex_lock(&data->time_mtx);
	phil_num = data->phil_num;
	pthread_mutex_unlock(&data->time_mtx);
	return (phil_num);
}

long	get_timedie(t_data *data)
{
	long	timedie;

	pthread_mutex_lock(&data->fin_meal_mtx);
	timedie = data->die_time;
	pthread_mutex_unlock(&data->fin_meal_mtx);
	return (timedie);
}

bool	get_end(t_data *data)
{
	bool	end;

	pthread_mutex_lock(&data->fin_mtx);
	end = data->finished;
	pthread_mutex_unlock(&data->fin_mtx);
	return (end);
}

long	get_mealnum(t_data *data)
{
	long	meal_num;

	pthread_mutex_lock(&data->fin_meal_mtx);
	meal_num = data->meal_num;
	pthread_mutex_unlock(&data->fin_meal_mtx);
	return (meal_num);
}

/*bool	get_finished_meal(t_data *philo)
{
	bool	end;

   	pthread_mutex_lock(&philo->fin_meal_mtx);
	end = philo.finished_meal;
	pthread_mutex_unlock(&philo->fin_meal_mtx);
	return (end);

}*/
