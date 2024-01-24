/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:15:29 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/24 19:36:15 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * if failed gettimeofday returns -1 && errno, 0 in case of success,
 * updates the struct timeval pointed to by tv with the current time.
 * ft_spin_lock is a spin-lock to repeatedly checking the time until
 * the specified time has passed, the thread dont yield the CPU to 
 * other thread during the wait
*/

void	spin_lock(unsigned long time)
{
	unsigned long	start;
	
	start = ft_gettime();
	while ((ft_gettime() - start) < time)
		usleep(time);
}

long	ft_gettime(void)
{
	struct	timeval tv;
	
	if(gettimeofday(&tv, NULL))
		printf(R"\t\ngettimeofday has encountered an error !\n"D);
	return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
}

int	isdigit_space(int v, char flag)
{
	if (flag == 'd')
		return (v >= '0' && v <= '9');
	else if (flag == 's')
		return (v == ' ' || (v >= '\t' && v <= '\r'));
	return (0);
}

long	ft_atol(char *str)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (isdigit_space(str[i], 's'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && isdigit_space(str[i], 'd'))
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	return (sign * result);
}
