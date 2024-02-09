/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:45:46 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/09 18:27:34 by avolcy           ###   ########.fr       */
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
	pthread_mutex_t	lock;
	t_data			*data;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	last_teat;
	long			time_to_die;
	int				nb_meal_eat;
	bool			finished_meal;
	long			last_time_eat;
}	t_philo;

typedef struct s_data
{
	pthread_t		*t_id;
	pthread_t		*mont;
	pthread_mutex_t	write;
//	pthread_mutex_t	fin_mtx;
	pthread_mutex_t	*forks;
	t_philo			*philo;
	bool			finished;
	long			phil_num;
	int				meal_num;	
	long			die_time;
	long			eat_time;
	long			sleep_time;
	long			start_time;
}		t_data;
#endif
