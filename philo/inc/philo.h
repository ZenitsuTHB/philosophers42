/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:07:52 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/20 04:18:51 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
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
# define D "\033[39m"
# define GRAY "\033[30m"

//# define D "\033[m"        //end
//# define R "\033[1;31m"    //red
//# define G "\033[1;32m"    //green
//# define Y "\033[1;33m"    //yellow
//# define B "\033[1;34m"    //blue
//# define T "\033[1;35m"	   //Turquesa
//# define C "\033[1;36m"    //Cyan
//# define O "\033[38;5;208m" //orange
//# define F "\033[38;5;128m"  //purple


# define ARG "\n\tThe provided arguments are not correct !\n\tTry like this :\n"
# define RAG "\t./philo [number_of_philosophers] [time_to_die] [time_to_eat]"
# define GAR "[time_to_sleep]\n\tif you wish [num_of_time_each_philo_must_eat]\n"

 
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
	bool			one_full;
	pthread_mutex_t	lock; 
	t_data			*data;//to grant access to philos to s_data;
	int				eating;
	pthread_mutex_t	*r_fork; 
	pthread_mutex_t	*l_fork;
	long			time_to_die;
}	t_philo;
   
typedef struct s_data
{
	bool	one_died;//whether a philo died💀 or all philos are full🍖
	bool	all_full;
	t_philo *philo;
	long	phil_num;
	long	meal_num;
	long	die_time;
	long	eat_time;
	long	sleep_time;
	long	start_time;
	pthread_t	*t_id; 
	pthread_t	tester; 
	pthread_mutex_t	write; 
	pthread_mutex_t	*forks;
}		t_data;

void	display_status(int status, char *msg, t_philo *philo);
void	clean_table(t_data *data);
int		start_dinner(t_data *data);
void    init_forks(t_data *data);
void	customed_usleep(long time);
void	init_philos(t_data *data);
long	ft_atol(char *str);
long	ft_gettime(void);
int		ft_isdigit(int v);
int		error_function(void);
int		check_num(char *s, int i);
int		check_args(int ac, char **av);
int		init_struct(t_data *data, char **argv);
int ft_exit(t_data *data, char *s);
#endif
