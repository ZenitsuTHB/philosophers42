/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:07:52 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/20 19:24:58 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include "struct.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define F 1
# define T -1

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

void	display_status(int status, char *msg, t_philo *philo);
void	clean_table(t_data *data);
int		start_dinner(t_data *data);
void    init_forks(t_data *data);
void	spin_lock(unsigned long time);
void	init_philos(t_data *data);
long	ft_atol(char *str);
long	ft_gettime(void);
int		isdigit_space(int v, char flag);
int		error_function(void);
int		check_num(char *s, int i);
int		check_args(int ac, char **av);
int		init_struct(t_data *data, char **argv);
int ft_exit(t_data *data, char *s);
#endif
