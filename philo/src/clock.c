/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:05 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/17 17:04:06 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	am_i_dead_wait(t_mind *m, long wait)
{
	struct timeval	now;
	long			init;

	if (wait < 1)
		return (false);
	gettimeofday(&now, NULL);
	init = now.tv_sec * 1e6 + now.tv_usec;
	while (1)
	{
		if (killed(m))
			return (true);
		gettimeofday(&now, NULL);
		if (now.tv_sec * 1e6 + now.tv_usec - init >= wait)
			break ;
		usleep(0);
	}
	return (false);
}

suseconds_t	get_time(suseconds_t start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1e6 + now.tv_usec - start) / 1e3);
}

suseconds_t	get_start(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1e6 + now.tv_usec);
}

void	*slow_death(void *ref)
{
	t_context	*c;

	c = ref;
	printf(MSG5, get_time(c->start), 1);
	lock(c->fork);
	unlock(c->fork);
	printf(MSG1, get_time(c->start), 1);
	usleep(c->set[DIE] * 1e3);
	return ((void *)false);
}
