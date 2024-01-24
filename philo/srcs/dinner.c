/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 03:33:22 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/24 20:46:23 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	display_status(int status, char *msg, t_philo *philo)
{
	 long	i;

	 pthread_mutex_lock(&philo->data->write);
	 if (philo->data->one_died == false)
	 {
		 pthread_mutex_lock(&philo->lock);
		 i = ft_gettime() - philo->data->start_time;
		 if (status == DIED)
			 printf(R"%ld Philo [%i] %s 🥱💀\n"D, i, philo->id, msg);
		 if (status == EATING)
			 printf(G"%ld Philo [%i] %s 🍜😋\n"D, i, philo->id, msg);
		 if (status == FORK)
			 printf(Y"%ld Philo [%i] %s 🍴🍴\n"D, i, philo->id, msg);
		 if (status == SLEEP)
			 printf(B"%ld Philo [%i] %s 🥱😴\n"D, i, philo->id, msg);
		 if (status == THINK)
			 printf(C"%ld Philo [%i] %s 🙄🤔\n"D, i, philo->id, msg);
		 pthread_mutex_unlock(&philo->lock);
	 }
	 pthread_mutex_unlock(&philo->data->write);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0)
		spin_lock(philo->data->eat_time);
	while (philo->data->one_died == false || philo->data->all_full == false)
	{
		take_the_forks(philo);
		eat_your_foods(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}

//void	*monitoring(void *arg)
//{
//}

int	start_dinner(t_data *data)
{
	int i;
	i = -1;
	data->start_time = ft_gettime();
	while(++i < data->phil_num)
	{
		pthread_create(&data->t_id[i], NULL, &routine, &data->philo[i]);
		usleep(1);
	}
//	if (pthread_create(&data->tester, NULL, &monitoring, data) != 0)
//		return (0);
	i = -1;
	while(++i < data->phil_num)
		pthread_join(data->t_id[i], NULL);
//	pthread_join(&data->tester, NULL);
	return (1);
}
