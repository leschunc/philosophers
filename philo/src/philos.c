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
	pthread_mutex_lock(m->inspec);
	// if (m->last_meal == -1)
	// {
	// 	pthread_mutex_unlock(m->inspec);
	// 	// printf("i was killed by monitor\n");
	// 	return (false);
	// 	// return (false);
	// }
	m->last_meal = now;
	m->meals++;
	if (m->set[CYCLE] != 0 && m->meals == m->set[CYCLE])
	{
		pthread_mutex_unlock(m->inspec);
		return (false);
	}
	pthread_mutex_unlock(m->inspec);
	return (true);
}

bool	eat_lr(t_mind *m)
{
	if (i_am_dead(m) == true)
		return (false);
	pthread_mutex_lock(m->l_fork);
	if (i_am_dead(m) == true)
	{
		pthread_mutex_unlock(m->l_fork);
		return (false);
	}
	printf(FORK, get_time(m->start), m->whoami);
	pthread_mutex_lock(m->r_fork);
	if (i_am_dead(m) == true)
	{
		pthread_mutex_unlock(m->r_fork);
		pthread_mutex_unlock(m->l_fork);
		return (false);
	}
	printf(FORK, get_time(m->start), m->whoami);
	pthread_mutex_unlock(m->l_fork);
	pthread_mutex_unlock(m->r_fork);
	return (true);
}

bool	eat_rl(t_mind *m)
{
	if (i_am_dead(m) == true)
		return (false);
	pthread_mutex_lock(m->r_fork);
	if (i_am_dead(m) == true)
	{
		pthread_mutex_unlock(m->r_fork);
		return (false);
	}
	printf(FORK, get_time(m->start), m->whoami);
	pthread_mutex_lock(m->l_fork);
	if (i_am_dead(m) == true)
	{
		pthread_mutex_unlock(m->l_fork);
		pthread_mutex_unlock(m->r_fork);
		return (false);
	}
	printf(FORK, get_time(m->start), m->whoami);
	pthread_mutex_unlock(m->r_fork);
	pthread_mutex_unlock(m->l_fork);
	return (true);
}

bool	grab(t_mind *m)
{
	if (m->whoami % 2 == 0)
	{
		if (eat_lr(m) == false)
			return (false);
		printf(EATS, get_time(m->start), m->whoami);
		if (set_last_meal(m) == false)
			return (false);
		usleep(m->set[EAT] * 1000);
	}
	else
	{
		usleep(1000);
		if (eat_rl(m) == false)
			return (false);
		printf(EATS, get_time(m->start), m->whoami);
		if (set_last_meal(m) == false)
			return (false);
		usleep(m->set[EAT] * 1000);
	}
	return (true);
}

bool	i_am_dead(t_mind *m)
{
	pthread_mutex_lock(m->inspec);
	if (m->last_meal == -1)
	{
		pthread_mutex_unlock(m->inspec);
		return (true);
	}
	pthread_mutex_unlock(m->inspec);
	return (false);
}

void	*daily(void *ref)
{
	t_mind	*m;

	m = (t_mind *)ref;
	while (1)
	{
		// if (i_am_dead == true)
		// 	return ((void *)false);
		printf(THNK, get_time(m->start), m->whoami);
		if (grab(m) == false)
			return ((void *)false);
		if (i_am_dead(m) == true)
			return ((void *)false);
		printf(NAPS, get_time(m->start), m->whoami);
		if (m->whoami % 2)
		{
			if (am_i_dead_wait(m, m->set[REST] * 1e3))
			{
				// printf(DIED, get_time(m->start), m->whoami);
				return ((void *)false);
			}
		}
		else if (am_i_dead_wait(m, m->set[REST] * 1e3 + 100))
		{
			// printf(DIED, get_time(m->start), m->whoami);
			return ((void *)false);
		}
	}
	return ((void *)false);
}
