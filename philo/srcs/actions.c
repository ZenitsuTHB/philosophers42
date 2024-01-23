/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:04:38 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/23 21:15:41 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_the_forks(t_philo *philo)
{
	if (philo->lf_taken == false)
	{
		pthread_mutex_lock(philo->l_fork);
		display_status(FORK, "has taken 1st fork", philo);
		philo->lf_taken = true;
	}
	if (philo->rf_taken == false)
	{
		pthread_mutex_lock(philo->r_fork);
		display_status(FORK, "has taken 2nd fork", philo);
		philo->rf_taken = true;
	}
}

void	eat_your_foods(t_philo *philo)
{
	if (philo->rf_taken == true && philo->lf_taken == true)
		philo->eaten++;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

//void	sleep_and_think(t_philo *philo)
//{
//}
