/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:22 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/14 03:12:03 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	set_last_meal(t_mind *m)
{
	suseconds_t	now;

	now = get_time(m->start[0]);
	lock(m->inspec);
	if (m->last_meal == -1)
	{
		unlock(m->inspec);
		return (false);
	}
	m->last_meal = now;
	m->meals++;
	if (m->set[CYC] != 0 && m->meals == m->set[CYC])
	{
		unlock(m->inspec);
		return (false);
	}
	unlock(m->inspec);
	return (true);
}

bool	eat_lr(t_mind *m)
{
	if (killed(m) == true)
		return (false);
	lock(m->l_fork);
	msg(HASFORK, m, 0, 0);
	if (killed(m) == true)
	{
		unlock(m->l_fork);
		return (false);
	}
	lock(m->r_fork);
	msg(HASFORK, m, 0, 0);
	msg(EATS, m, 0, 0);
	if (set_last_meal(m) == false)
		return (unlock(m->l_fork), unlock(m->r_fork), false);
	if (am_i_dead_wait(m, m->set[EAT] * 1000))
		return (unlock(m->l_fork), unlock(m->r_fork), false);
	return (unlock(m->r_fork), unlock(m->l_fork), true);
}

bool	eat_rl(t_mind *m)
{
	if (killed(m) == true)
	{
		return (false);
	}
	lock(m->r_fork);
	msg(HASFORK, m, 0, 0);
	if (killed(m) == true)
	{
		unlock(m->r_fork);
		return (false);
	}
	lock(m->l_fork);
	msg(HASFORK, m, 0, 0);
	msg(EATS, m, 0, 0);
	if (set_last_meal(m) == false)
		return (unlock(m->l_fork), unlock(m->r_fork), false);
	if (am_i_dead_wait(m, m->set[EAT] * 1e3))
		return (unlock(m->l_fork), unlock(m->r_fork), false);
	return (unlock(m->r_fork), unlock(m->l_fork), true);
}

bool	grab(t_mind *m)
{
	if (m->whoami % 2 == 0)
	{
		if (eat_lr(m) == false)
			return (false);
	}
	else
	{
		if (am_i_dead_wait(m, 1e3))
			return (false);
		if (eat_rl(m) == false)
			return (false);
	}
	return (true);
}

void	*daily(void *ref)
{
	t_mind	*m;

	m = (t_mind *)ref;
	while (1)
	{
		if (killed(m) == true)
			return ((void *)false);
		msg(THINKS, m, 0, 0);
		if (!m->whoami % 2)
			if (am_i_dead_wait(m, pos(2 * m->set[EAT] - m->set[SLP])))
				return ((void *)false);
		if (grab(m) == false)
			return ((void *)false);
		if (killed(m) == true)
			return ((void *)false);
		msg(SLEEPS, m, 0, 0);
		if (m->whoami % 2)
		{
			if (am_i_dead_wait(m, m->set[SLP] * 1e3))
				return ((void *)false);
		}
		else if (am_i_dead_wait(m, m->set[SLP] * 1e3 + 100))
			return ((void *)false);
	}
	return ((void *)false);
}
