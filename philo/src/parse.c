/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:37:56 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/15 16:14:41 by leschunc         ###   ########.fr       */
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
		if (ft_strlen(str) > 10)
			return (false);
		if (ft_strlen(str) == 10)
		{
			if (cmp(str, "2147483647") > 0)
			{
				printf("hi\n");
				return (false);
			}
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
	pthread_create(&omega, NULL, slow_death, c);
	pthread_join(omega, NULL);
	printf(ERR2, get_time(c->start[0]), 1);
	pthread_mutex_destroy(&single_fork);
	return (true);
}

bool	atoiv(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->arr_len)
	{
		if (pre_check(c->argv[i + 1]) == false)
		{
			printf("Digit-only non-zero INTs allowed\n");
			return (ERR);
		}
		c->set[i] = atonum(c->argv[i + 1]);
		if (c->set[i] == 0)
		{
			printf("Digit-only non-zero INTs allowed\n");
			return (ERR);
		}
		i++;
	}
	if (c->set[NUM] == 1)
	{
		c->start[0] = get_start();
		one_lonely_philo(c);
		return (ERR);
	}
	if (c->set[NUM] > SIM_MAX)
		return (printf(ERR1, c->set[NUM]), ERR);
	return (OK);
}
