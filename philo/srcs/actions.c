/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:04:38 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/24 20:46:19 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_the_forks(t_philo *philo)
{
	if (philo->lf_taken == false)
	{
		pthread_mutex_lock(philo->l_fork);
		display_status(FORK, "has taken 1st fork", philo);
		pthread_mutex_lock(&philo->lock);
		philo->lf_taken = true;
		pthread_mutex_unlock(&philo->lock);
	}
	if (philo->rf_taken == false)
	{
		pthread_mutex_lock(philo->r_fork);
		display_status(FORK, "has taken 2nd fork", philo);
		pthread_mutex_lock(&philo->lock);
		philo->rf_taken = true;
		pthread_mutex_unlock(&philo->lock);
	}
}

void	eat_your_foods(t_philo *philo)
{
	if (philo->rf_taken == true && philo->lf_taken == true)
	{
		philo->eaten++;
		display_status(EATING, "is eating", philo);
		spin_lock(philo->data->eat_time);
	}
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_lock(&philo->lock);
	philo->lf_taken = false;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_lock(&philo->lock);
	philo->rf_taken = false;
	pthread_mutex_unlock(&philo->lock);
}

void	sleep_and_think(t_philo *philo)
{
	display_status(SLEEP, "is sleeping", philo);
	spin_lock(philo->data->sleep_time);
	display_status(THINK, "is thinking", philo);
}
