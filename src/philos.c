#include "philo.h"

static inline suseconds_t	fast_ms(suseconds_t start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000000 + now.tv_usec - start) / 1000);
}

void	grab(t_mind m)
{
	if (m.whoami % 2 == 0)
	{
		pthread_mutex_lock(m.l_fork);
		printf("[%ld]\t[%d]\t[%ld]\tR\n", fast_ms(m.start), m.whoami, m.meals);
		pthread_mutex_lock(m.r_fork);
		printf("[%ld]\t[%d]\t[%ld]\tL\n", fast_ms(m.start), m.whoami, m.meals);
	}
	else
	{
		pthread_mutex_lock(m.r_fork);
		printf("[%ld]\t[%d]\t[%ld]\tR\n", fast_ms(m.start), m.whoami, m.meals);
		pthread_mutex_lock(m.l_fork);
		printf("[%ld]\t[%d]\t[%ld]\tL\n", fast_ms(m.start), m.whoami, m.meals);
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
		if (m->set[CYCLE] !=0 && m->meals == m->set[CYCLE])
			return (pthread_mutex_unlock(m->inspec), NULL);
		(m->meals)++;
		pthread_mutex_unlock(m->inspec);
		// usleep seems better
		// 1000 maybe
		// this defo looks more precise and safe
		usleep(100);
		// fast_wait(100);
	}
	return (NULL);
}
