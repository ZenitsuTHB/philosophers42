/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:04:38 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/09 18:59:43 by avolcy           ###   ########.fr       */
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

static	void	drop_fork(t_philo *philo)
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
	philo->nb_meal_eat++;
	if (philo->nb_meal_eat == philo->data->meal_num)
		philo->finished_meal = true;
	pthread_mutex_lock(&philo->last_teat);
	philo->last_time_eat = ft_gettime();
	pthread_mutex_unlock(&philo->last_teat);
	drop_fork(philo);
}

void	sleep_and_think(t_philo *philo)
{
	display_status(SLEEP, "is sleeping", philo);
	spin_lock(philo->data->sleep_time);
	display_status(THINK, "is thinking", philo);
}

void	display_status(int status, char *msg, t_philo *philo)
{
	long	i;

	pthread_mutex_lock(&philo->data->write);
	i = ft_gettime() - philo->data->start_time;
	if (status == DIED)
		printf(R"%ld Philo [%i] %s 🥱💀\n"D, i, philo->id, msg);
	else if (philo->data->finished == false)
	{
		i = ft_gettime() - philo->data->start_time;
		if (status == EATING)
			printf(G"%ld Philo [%i] %s 🍜😋\n"D, i, philo->id, msg);
		else if (status == FORK)
			printf(Y"%ld Philo [%i] %s 🍴🍴\n"D, i, philo->id, msg);
		else if (status == SLEEP)
			printf(B"%ld Philo [%i] %s 🥱😴\n"D, i, philo->id, msg);
		else if (status == THINK)
			printf(C"%ld Philo [%i] %s 🙄🤔\n"D, i, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->write);
}
