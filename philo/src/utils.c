/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:25 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/18 14:46:33 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	unlock(t_mut *mut)
{
	pthread_mutex_unlock(mut);
}

void	lock(t_mut *mut)
{
	pthread_mutex_lock(mut);
}

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str)
// 		while (str[i])
// 			i++;
// 	return (i);
// }

int	ft_putstr(char *str)
{
	if (str)
		return (write(1, str, ft_strlen(str)));
	return (-1);
}

void	putn_buf(int num)
{
	char	buf[10];
	int		size;
	int		ref;

	if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	size = 0;
	ref = num;
	while (ref > 0)
	{
		ref /= 10;
		size++;
	}
	ref = size;
	while (num > 0)
	{
		buf[ref - 1] = (num % 10) + '0';
		num /= 10;
		ref--;
	}
	write(1, buf, size);
}
