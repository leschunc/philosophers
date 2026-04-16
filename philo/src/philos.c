/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:22 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/16 13:06:19 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	set_last_meal(t_mind *m)
{
	suseconds_t	now;

	now = get_time(m->start[0]);
	lock(m->inspec);
	if (m->last_meal == -1)
		return (unlock(m->inspec), false);
	m->last_meal = now;
	m->meals++;
	if (m->meals == m->set[CYC])
		return (unlock(m->inspec), false);
	return (unlock(m->inspec), true);
}

bool	left_right(t_mind *m)
{
	lock(m->l_fork);
	msg(HASFORKS, m, 0, 0);
	if (killed(m) == true)
		return (unlock(m->l_fork), false);
	lock(m->r_fork);
	msg(HASFORK, m, 0, 0);
	msg(EATS, m, 0, 0);
	if (set_last_meal(m) == false)
		return (unlock(m->l_fork), unlock(m->r_fork), false);
	if (am_i_dead_wait(m, m->set[EAT] * 1e3))
		return (unlock(m->l_fork), unlock(m->r_fork), false);
	return (unlock(m->r_fork), unlock(m->l_fork), true);
}

bool	right_left(t_mind *m)
{
	lock(m->r_fork);
	msg(HASFORK, m, 0, 0);
	if (killed(m) == true)
		return (unlock(m->r_fork), false);
	lock(m->l_fork);
	msg(HASFORKS, m, 0, 0);
	msg(EATS, m, 0, 0);
	if (set_last_meal(m) == false)
		return (unlock(m->r_fork), unlock(m->l_fork), false);
	if (am_i_dead_wait(m, m->set[EAT] * 1e3))
		return (unlock(m->r_fork), unlock(m->l_fork), false);
	return (unlock(m->l_fork), unlock(m->r_fork), true);
}

bool	eating(t_mind *m)
{
	if (m->whoami == 0)
	{
		if (left_right(m) == false)
			return (false);
	}
	else
	{
		if (right_left(m) == false)
			return (false);
	}
	return (true);
}

// bool	even(t_mind *m)
// {
// 	long	timeout;

// 	timeout = m->set[EAT] - m->set[SLP];
// 	while (1)
// 	{
// 		if (eating(m) == false)
// 			return (false);
// 		msg(SLEEPS, m, 0, 0);
// 		if (am_i_dead_wait(m, m->set[SLP] * 1e3))
// 			return (true);
// 		msg(THINKS, m, 0, 0);
// 		if (am_i_dead_wait(m, timeout))
// 			return (true);
// 		return (true);
// 	}
// }

// bool	odd(t_mind *m)
// {
// }

void	*daily(void *ref)
{
	t_mind	*m;
	long	timeout;

	m = (t_mind *)ref;
	timeout = m->set[EAT] * (m->set[NUM] % 2 + 1) - m->set[SLP] + 100;
	while (1)
	{
		if (eating(m) == false)
			return ((void *)0);
		msg(SLEEPS, m, 0, 0);
		if (am_i_dead_wait(m, m->set[SLP] * 1e3))
			return ((void *)0);
		msg(THINKS, m, 0, 0);
		if (am_i_dead_wait(m, timeout))
			return ((void *)0);
	}
	return ((void *)1);
}
