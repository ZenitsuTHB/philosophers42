/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:04:38 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/30 19:19:50 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_the_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	display_status(FORK, "has taken 1st fork", philo);
	pthread_mutex_lock(philo->r_fork);
	display_status(FORK, "has taken 2nd fork", philo);
}

static	void drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	display_status(FORK, "has drop 1st fork", philo);
	pthread_mutex_unlock(philo->r_fork);
	display_status(FORK, "has drop 2nd fork", philo);
}

void	eat_your_foods(t_philo *philo)
{
	display_status(EATING, "is eating", philo);
	spin_lock(philo->data->eat_time);
	philo->nb_meal_eat += 1;
	//philo->data->all_full += 1;
	philo->last_time_eat = ft_gettime();
	drop_fork(philo);
}

void	sleep_and_think(t_philo *philo)
{
	display_status(SLEEP, "is sleeping", philo);
	spin_lock(philo->data->sleep_time);
	display_status(THINK, "is thinking", philo);
}
