/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:37:56 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/17 14:19:48 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	cmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	pre_check(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		if (*str == '+')
			str++;
		while (*str == '0')
			str++;
		if (ft_strlen(str) > 10)
			return (false);
		if (ft_strlen(str) == 10)
		{
			if (cmp(str, "2147483647") > 0)
				return (false);
		}
		while (str[i])
		{
			if (ft_isdigit(str[i]) == false)
				return (false);
			i++;
		}
	}
	return (true);
}

bool	one_lonely_philo(t_context *c)
{
	pthread_mutex_t	single_fork;
	pthread_t		omega;

	c->fork = &single_fork;
	pthread_mutex_init(&single_fork, NULL);
	c->start = get_start();
	if (pthread_create(&omega, NULL, slow_death, c))
		return (pthread_join(omega, NULL), false);
	pthread_join(omega, NULL);
	printf(E_MURD, get_time(c->start), 1);
	return (true);
}

bool	atoiv(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->arr_len)
	{
		if (pre_check(c->argv[i + 1]) == false)
			return (printf(E_RANGE), ERR);
		c->set[i] = atonum(c->argv[i + 1]);
		if (c->set[i] == 0)
			return (printf(E_INT), ERR);
		i++;
	}
	if (c->set[NUM] > SIM_MAX)
		return (printf(E_MANY, c->set[NUM]), ERR);
	return (OK);
}
