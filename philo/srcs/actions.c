/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:04:38 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/14 18:06:39 by avolcy           ###   ########.fr       */
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
	if (philo->nb_meal_eat == get_mealnum(philo->data))
		set_finished_meal(philo);
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
	long	start;

	pthread_mutex_lock(&philo->data->time_mtx);
	start = philo->data->start_time;
	pthread_mutex_unlock(&philo->data->time_mtx);
	i = ft_gettime() - start;
	if (status == DIED)
		printf(R"%ld ms Philo [%i] %s\n"D, i, philo->id, msg);
	pthread_mutex_lock(&philo->data->write);
	if (get_end(philo->data) == false)
	{
		pthread_mutex_unlock(&philo->data->fin_mtx);
		i = ft_gettime() - start;
		if (status == EATING)
			printf(G"%ld ms Philo [%i] %s\n"D, i, philo->id, msg);
		else if (status == FORK)
			printf(Y"%ld ms Philo [%i] %s\n"D, i, philo->id, msg);
		else if (status == SLEEP)
			printf(B"%ld ms Philo [%i] %s\n"D, i, philo->id, msg);
		else if (status == THINK)
			printf(C"%ld ms Philo [%i] %s\n"D, i, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->write);
}
