/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 03:33:22 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/30 20:21:52 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * checks if the philosopher's ID is even means si es par
 * curtime - utilma < dietime = vivo
 */
void	display_status(int status, char *msg, t_philo *philo)
{
	 long	i;
	
	pthread_mutex_lock(&philo->data->write);
		i = ft_gettime() - philo->data->start_time;
	if (philo->data->one_died == true && status == DIED)
			printf(R"%ld Philo [%i] %s 🥱💀\n"D, i, philo->id, msg);
	else if (philo->data->one_died == false || philo->data->all_full == false)
	{
		i = ft_gettime() - philo->data->start_time;
		pthread_mutex_lock(&philo->lock);
		if (status == EATING)
			printf(G"%ld Philo [%i] %s 🍜😋\n"D, i, philo->id, msg);
		if (status == FORK)
			printf(Y"%ld Philo [%i] %s 🍴🍴\n"D, i, philo->id, msg);
		if (status == SLEEP)
			printf(B"%ld Philo [%i] %s 🥱😴\n"D, i, philo->id, msg);
		if (status == THINK)
			printf(C"%ld Philo [%i] %s 🙄🤔\n"D, i, philo->id, msg);
		pthread_mutex_unlock(&philo->lock);
		pthread_mutex_unlock(&philo->data->write);
	 }
}

//static	void	allfull(t_data *data)
//{
//	int	i;
//
//	i = -1;
//	while (++i < data->phil_num)
//	{
//		if (data
//	}
//}

void	*monitoring(t_data *data)
{
	int	i;

	i = -1;
	while (1)
	{
		if (ft_gettime() - data->philo->last_time_eat > data->die_time)
		{
			data->one_died = true;
			ft_exit(data, "is dead");
			break ;
		}
	}
	return ((void *)0);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0)
		spin_lock(philo->data->eat_time);
	if (philo->data->one_died == true)
		return NULL; 
	while (philo->data->one_died == false)
	{
		take_the_forks(philo);
		eat_your_foods(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}

int	start_dinner(t_data *data)
{
	int i;
	i = -1;
	data->start_time = ft_gettime();
	while(++i < data->phil_num)
	{
		data->philo[i].last_time_eat = data->start_time;
		pthread_create(&data->t_id[i], NULL, &routine, &data->philo[i]);
		usleep(1);
	}
	monitoring(data);
	i = -1;
	while(++i < data->phil_num)
		pthread_detach(data->t_id[i]);
	return (1);
}
