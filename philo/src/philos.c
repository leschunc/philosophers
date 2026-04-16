/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:22 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/16 00:53:36 by leschunc         ###   ########.fr       */
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

bool	eat_lr(t_mind *m)
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

bool	eat_rl(t_mind *m)
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

bool	grab(t_mind *m)
{
	if (m->whoami == 0)
	{
		if (eat_lr(m) == false)
			return (false);
	}
	else
	{
		if (eat_rl(m) == false)
			return (false);
	}
	return (true);
}

bool	even(t_mind *m)
{
	msg(THINKS, m, 0, 0);
	if (m->whoami % 2 == ODD)
		if (am_i_dead_wait(m, 2 * m->set[EAT] - m->set[SLP]))
			return (false);
	if (grab(m) == 0)
		return (false);
	msg(SLEEPS, m, 0, 0);
	if (am_i_dead_wait(m, m->set[SLP] * 1e3))
		return (false);
	return (true);
}

bool	odd(t_mind *m)
{
	long	remainder;

	msg(THINKS, m, 0, 0);
	remainder = get_time(m->start[0]) - ((m->set[EAT] + m->set[SLP]));
	if (m->whoami % 2 == ODD)
		while (remainder < m->set[DIE] * 0.7)
		{
			am_i_dead_wait(m, remainder / 2);
			remainder = get_time(m->start[0]) - ((m->set[EAT] + m->set[SLP]));
		}
	if (grab(m) == 0)
		return (false);
	msg(SLEEPS, m, 0, 0);
	if (am_i_dead_wait(m, m->set[SLP] * 1e3))
		return (false);
	return (true);
}

void	*daily(void *ref)
{
	t_mind	*m;

	m = (t_mind *)ref;
	if (m->set[NUM] % 2 == ODD)
	{
		if (odd(m) == false)
			return ((void *)0);
	}
	else
		while (1)
		{
			if (even(m) == false)
				break ;
		}
	return ((void *)0);
}
