/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:45:46 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/14 16:48:09 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include <pthread.h>

typedef struct s_data	t_data;

typedef enum e_status
{
	DIED,
	EATING,
	FORK,
	SLEEP,
	THINK,
	EXIT
}	t_status;

typedef struct s_philo
{
	int				id;
	long			time_to_die;
	int				nb_meal_eat;
	bool			finished_meal;
	long			last_time_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	last_teat;
	t_data			*data;
	pthread_t		t_id;
}	t_philo;

typedef struct s_data
{
	long			phil_num;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	int				meal_num;
	long			start_time;
	bool			finished;
	pthread_mutex_t	write;
	pthread_mutex_t	fin_mtx;
	pthread_mutex_t	fin_meal_mtx;
	pthread_mutex_t	time_mtx;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}		t_data;
#endif
