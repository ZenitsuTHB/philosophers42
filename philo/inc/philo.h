/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:07:52 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/31 17:27:28 by avolcy           ###   ########.fr       */
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

# define ARG "\n\tThe provided arguments are not correct !\n\tTry like this :\n"
# define RAG "\t./philo [number_of_philosophers] [time_to_die] [time_to_eat]"
# define GAR "[time_to_sleep]\n\tif you wish [num_of_time_each_philo_must_eat]\n"

typedef struct s_data
{
	int	dietime;
	int	philnum;
	int	eattime;
	int	bedtime;
	int	mealnum;
}	t_data;

long	ft_atol(char *str);
int		ft_isdigit(int v);
void	error_function(void);
int		check_num(char *s, int i);
int		check_args(int ac, char **av);
#endif

