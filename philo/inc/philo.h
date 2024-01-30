/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:07:52 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/27 13:39:31 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include "struct.h"
# include "macros.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

void	display_status(int status, char *msg, t_philo *philo);
void	take_the_forks(t_philo *philo);
void	eat_your_foods(t_philo *philo);
void	sleep_and_think(t_philo *philo);
void	clean_table(t_data *data);
int		start_dinner(t_data *data);
void    init_the_forks(t_data *data);
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
