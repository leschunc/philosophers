#include "philo.h"

static inline suseconds_t	get_usec_fast(void)
{
	struct timeval	now;
	suseconds_t		u_time;

	gettimeofday(&now, NULL);
	u_time = now.tv_sec * 1000000;
	u_time += now.tv_usec;
	return (u_time);
}

void	grab(t_mind m)
{
	// struct timeval	now;
	if (m.whoami % 2 == 0)
	{
		pthread_mutex_lock(m.l_fork);
		pthread_mutex_lock(m.r_fork);
	}
	else
	{
		pthread_mutex_lock(m.r_fork);
		pthread_mutex_lock(m.l_fork);
	}
}

void	drop(t_mind m)
{
	pthread_mutex_unlock(m.r_fork);
	pthread_mutex_unlock(m.l_fork);
}

void	*daily(void *ref)
{
	t_mind	*m;

	m = (t_mind *)ref;
	m->meals = 0;
	while (1)
	{
		grab(*m);
		drop(*m);
		pthread_mutex_lock(m->inspec);
		if (m->set[CYCLE])
		{
			if (m->meals == m->set[CYCLE])
				return (pthread_mutex_unlock(m->inspec), NULL);
			(m->meals)++;
		}
		pthread_mutex_unlock(m->inspec);
		// usleep seems better
		// usec_wait(1000);
		// 1000 maybe
		fast_ahh_wait(m->set[NUM]);
	}
	return (NULL);
}
