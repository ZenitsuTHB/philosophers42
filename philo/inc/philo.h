/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:07:52 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/03 20:54:32 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define T 1
# define F -1

# define R "\033[31m"
# define G "\033[32m"
# define Y "\033[33m"
# define B "\033[34m"
# define M "\033[35m"
# define C "\033[36m"
# define W "\033[37m"
# define DEF "\033[39m"
# define GRAY "\033[30m"

# define ARG "\n\tThe provided arguments are not correct !\n\tTry like this :\n"
# define RAG "\t./philo [number_of_philosophers] [time_to_die] [time_to_eat]"
# define GAR "[time_to_sleep]\n\tif you wish [num_of_time_each_philo_must_eat]\n"

 
typedef struct s_data t_data;
typedef struct pthread_mutex_t t_mtx;

typedef struct s_fork
{
	t_mtx	*fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				full;
	t_data			*data;//to grant access to philos to s_data;
	pthread_mutex_t	lock; 
	pthread_mutex_t	*r_fork; 
	pthread_mutex_t	*l_fork;
}	t_philo;
   
struct s_data
{
	int		died;//whether a philo died💀 or all philos are full🍖
	t_philo *philo;
	pthread_mutex_t	*forks;
	long	phil_num;
	long	meal_num;
	long	die_time;
	long	eat_time;
	long	sleep_time;
	long	start_time;
	pthread_mutex_t	lock; 
};


void	init_philos(t_data *data);
long	ft_atol(char *str);
long	ft_get_time(void);
int		ft_isdigit(int v);
int		error_function(void);
int		check_num(char *s, int i);
int		check_args(int ac, char **av);
int		init_struct(t_data *data, char **argv);

#endif

