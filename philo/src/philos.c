#include "philo.h"

// static inline void	hi_res_wait(long wait)
// {
// 	struct timeval	now;
// 	long			init;

// 	gettimeofday(&now, NULL);
// 	init = now.tv_sec * 1000000 + now.tv_usec;
// 	while (1)
// 	{
// 		gettimeofday(&now, NULL);
// 		if (now.tv_sec * 1000000 + now.tv_usec - init >= wait)
// 			break ;
// 		usleep(wait / 3);
// 		// magic number for luck
// 		// usleep(set[NUM] / 3);
// 	}
// }

bool	set_last_meal(t_mind *m)
{
	suseconds_t	now;

	now = get_time(m->start);
	lock(m->inspec);
	m->last_meal = now;
	if (m->meals == -1)
	{
		unlock(m->inspec);
		return (false);
	}
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
		return (false);
	if (am_i_dead_wait(m, m->set[EAT] * 1000))
	{
		unlock(m->r_fork);
		unlock(m->l_fork);
		return (false);
	}
	unlock(m->l_fork);
	unlock(m->r_fork);
	return (true);
}

bool	eat_rl(t_mind *m)
{
	if (killed(m) == true)
		return (false);
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
		return (false);
	if (am_i_dead_wait(m, m->set[EAT] * 1e3))
	{
		unlock(m->l_fork);
		unlock(m->r_fork);
		return (false);
	}
	unlock(m->r_fork);
	unlock(m->l_fork);
	return (true);
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

bool	killed(t_mind *m)
{
	lock(m->inspec);
	if (m->last_meal == -1)
	{
		unlock(m->inspec);
		return (true);
	}
	unlock(m->inspec);
	return (false);
}

void	*daily(void *ref)
{
	t_mind	*m;

	m = (t_mind *)ref;
	while (1)
	{
		// if (killed == true)
		// 	return ((void *)false);
		msg(THINKS, m, 0, 0);
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
