/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:18 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/18 00:01:25 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	turn_minds_off(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->set[NUM])
	{
		lock(c->inspec + i);
		c->mind[i].last_meal = -1;
		unlock(c->inspec + i);
		i++;
	}
}

bool	safe_inspec(t_context *c, int i)
{
	static int	finished = 0;
	suseconds_t	now;

	now = get_time(c->start);
	lock(c->inspec + i);
	if (c->set[CYC] && c->set[CYC] == c->mind[i].meals)
	{
		finished++;
		c->mind[i].meals = -1;
		if (finished == c->set[NUM])
			return (unlock(c->inspec + i), false);
	}
	else if (now - c->mind[i].last_meal > c->set[DIE])
	{
		unlock(c->inspec + i);
		lock(&c->broadcast);
		c->simulation = false;
		unlock(&c->broadcast);
		msg(DIED, NULL, c, i);
		return (turn_minds_off(c), false);
	}
	unlock(c->inspec + i);
	return (true);
}

void	*fate(void *ref)
{
	t_context	*c;
	int			i;

	c = ref;
	lock(&c->broadcast);
	unlock(&c->broadcast);
	while (1)
	{
		i = 0;
		while (i < c->set[NUM])
		{
			if (safe_inspec(c, i) == false)
				return (NULL);
			i++;
		}
		usleep(1000 / c->set[NUM]);
	}
	return (NULL);
}

void	give_free_will(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->set[NUM])
	{
		c->mind[i].whoami = i;
		c->mind[i].inspec = c->inspec + i;
		c->mind[i].r_fork = c->fork + i;
		c->mind[i].meals = 0;
		c->mind[i].last_meal = 0;
		c->mind[i].set = c->set;
		c->mind[i].broadcast = &c->broadcast;
		c->mind[i].simulation = &c->simulation;
		c->mind[i].start = &c->start;
		if (i == 0)
			c->mind[i].l_fork = &c->fork[c->set[NUM] - 1];
		else
			c->mind[i].l_fork = &c->fork[i - 1];
		i++;
	}
}

void	destroy_mutx(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->set[NUM])
	{
		pthread_mutex_destroy(c->fork + i);
		i++;
	}
	i = 0;
	if (c->set[CYC] == 0)
		return ;
	while (i < c->set[NUM])
	{
		pthread_mutex_destroy(c->inspec + i);
		i++;
	}
}
