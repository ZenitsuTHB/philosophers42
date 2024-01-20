/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:15:29 by avolcy            #+#    #+#             */
/*   Updated: 2024/01/20 03:55:11 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 * in case of faillure gettimeofday returns -1 && errno
 * 0 in case of success
 * if successful, it updates the struct timeval 
 * pointed to by tv with the current time.
*/

//void	ft_usleep(long time)
//{
//}
long	ft_gettime(void)
{
	struct timeval	tv;

	if(gettimeofday(&tv, NULL))
		printf("\t\n%sgettimeofday has encountered an error !%s\n", R, D);
	return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
}

int	ft_isdigit(int v)
{
	if (v >= 48 && v <= 57)
		return (1);
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
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	return (sign * result);
}
