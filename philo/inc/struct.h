/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:45:46 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/30 19:09:06 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <stdbool.h>
#include <pthread.h>

typedef struct s_data t_data;
//typedef struct pthread_mutex_t t_mtx;

typedef enum e_status
{
	DIED,
	EATING,
	FORK,
	SLEEP,
	THINK
}	t_status;

typedef struct s_philo
{
	int				id;
	int				one_full;
	pthread_mutex_t	lock;
	t_data			*data;//to grant access to philos to s_data;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				nb_meal_eat;
	long			last_time_eat;
	long			time_to_die;
}	t_philo;

typedef struct s_data
{
	bool	one_died;//whether a philo died💀 or all philos are full🍖
	int		all_full;
	t_philo *philo;
	long	phil_num;
	int		meal_num;
	long	die_time;
	long	eat_time;
	long	sleep_time;
	long	start_time;
	pthread_t	*t_id;
	pthread_t	tester;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
}		t_data;
#endif
