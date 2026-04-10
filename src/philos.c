#include "philo.h"

static inline suseconds_t	fast_ms(suseconds_t start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000000 + now.tv_usec - start) / 1000);
}

static inline void	hi_res_wait(long wait)
{
	struct timeval	now;
	long			init;

	gettimeofday(&now, NULL);
	init = now.tv_sec * 1000000 + now.tv_usec;
	while (1)
	{
		gettimeofday(&now, NULL);
		if (now.tv_sec * 1000000 + now.tv_usec - init >= wait)
			break ;
		usleep(wait / 3);
		// magic number for luck
		// usleep(set[NUM] / 3);
	}
}

bool	set_last_meal(t_mind *m)
{
	suseconds_t	now;

	pthread_mutex_lock(m->inspec);
	now = fast_ms(m->start);
	if (now - m->last_meal > m->set[DIE])
	{
		printf("i died\n");
		return (pthread_mutex_unlock(m->inspec), false);
	}
	m->last_meal = now;
	m->meals++;
	if (m->set[CYCLE] != 0 && m->meals == m->set[CYCLE])
	{
		printf("i finished\n");
		return (pthread_mutex_unlock(m->inspec), false);
	}
	pthread_mutex_unlock(m->inspec);
	return (true);
}

bool	grab(t_mind *m)
{
	if (m->whoami % 2 != 0)
	{
		pthread_mutex_lock(m->l_fork);
		printf("%03d\t%05ld\t%ld\tL\n", m->whoami, fast_ms(m->start), m->meals);
		pthread_mutex_lock(m->r_fork);
		printf("%03d\t%05ld\t%ld\tR\n", m->whoami, fast_ms(m->start), m->meals);
		if (set_last_meal(m) == false)
			return (printf("%d died or finished\n", m->whoami), false);
		usleep(m->set[EAT] * 1000);
	}
	else
	{
		usleep(100);
		pthread_mutex_lock(m->r_fork);
		printf("%03d\t%05ld\t%ld\tR\n", m->whoami, fast_ms(m->start), m->meals);
		pthread_mutex_lock(m->l_fork);
		printf("%03d\t%05ld\t%ld\tL\n", m->whoami, fast_ms(m->start), m->meals);
		if (set_last_meal(m) == false)
			return (printf("%d died\n", m->whoami), false);
		usleep(m->set[EAT] * 1000);
	}
	return (true);
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
		if (grab(m) == false)
			return (drop(*m), (void *)false);
		drop(*m);
		// pthread_mutex_lock(m->inspec);
		// usleep seems better
		// 1000 maybe
		// this defo looks more precise and safe
		if (m->whoami % 2)
			usleep(m->set[REST] * 1000);
		else
			usleep(m->set[REST] * 1000 + 100);
		// fast_wait(100);
	}
	return ((void *)false);
}
