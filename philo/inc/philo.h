/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:07:52 by avolcy            #+#    #+#             */
/*   Updated: 2024/02/08 20:33:41 by avolcy           ###   ########.fr       */
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

/*-------|_PHILO_|-----------*/
int		ft_clear(t_data	*data);
int		check_num(char *s, int i);
int		check_args(int ac, char **av);

/*--------|_UTILS_|-----*/
long	ft_gettime(void);
long	ft_atol(char *str);
void	spin_lock(unsigned long time);
int		isdigit_space(int v, char flag);

/*---------|_INIT_|-------------*/
void	init_philos(t_data *data);
void	init_the_forks(t_data *data);
int		init_struct(t_data *data, char **argv);

/*---------|_DINNER_|-------------*/
int		start_dinner(t_data *data);
int		ft_exit(t_data *data, char *s);

/*-----------|_ACTION_|--------------*/
void	take_the_forks(t_philo *philo);
void	eat_your_foods(t_philo *philo);
void	sleep_and_think(t_philo *philo);
void	display_status(int status, char *msg, t_philo *philo);

#endif
