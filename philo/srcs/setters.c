/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:44:00 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/14 18:05:00 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_finished(t_data *data)
{
	bool	end;

	end = true;
	pthread_mutex_lock(&data->fin_mtx);
	data->finished = end;
	pthread_mutex_unlock(&data->fin_mtx);
}

void	set_finished_meal(t_philo *philo)
{
	bool	end;

	end = true;
	pthread_mutex_lock(&philo->data->fin_meal_mtx);
	philo->finished_meal = end;
	pthread_mutex_unlock(&philo->data->fin_meal_mtx);
}
