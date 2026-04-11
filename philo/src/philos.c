#include "philo.h"

static inline suseconds_t	fast_ms(suseconds_t start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000000 + now.tv_usec - start) / 1000);
}

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

	now = fast_ms(m->start);
	pthread_mutex_lock(m->inspec);
	if (m->last_meal == -1)
	{
		pthread_mutex_unlock(m->inspec);
		// printf("i was killed by monitor\n");
		exit(EXIT_FAILURE);
		// return (false);
	}
	m->last_meal = now;
	m->meals++;
	pthread_mutex_unlock(m->inspec);
	if (m->set[CYCLE] != 0 && m->meals == m->set[CYCLE])
		return (false);
	return (true);
}


void	eat_lr(t_mind *m)
{
	pthread_mutex_lock(m->l_fork);
	printf(FORK, fast_ms(m->start), m->whoami);
	pthread_mutex_lock(m->r_fork);
	printf(FORK, fast_ms(m->start), m->whoami);
	pthread_mutex_unlock(m->l_fork);
	pthread_mutex_unlock(m->r_fork);
}

void	eat_rl(t_mind *m)
{
	pthread_mutex_lock(m->r_fork);
	printf(FORK, fast_ms(m->start), m->whoami);
	pthread_mutex_lock(m->l_fork);
	printf(FORK, fast_ms(m->start), m->whoami);
	pthread_mutex_unlock(m->r_fork);
	pthread_mutex_unlock(m->l_fork);
}

bool	grab(t_mind *m)
{
	if (m->whoami % 2 != 0)
	{
		eat_lr(m);
		printf(EATS, fast_ms(m->start), m->whoami);
		if (set_last_meal(m) == false)
			return (false);
		usleep(m->set[EAT] * 1000);
	}
	else
	{
		usleep(100);
		eat_rl(m);
		printf(EATS, fast_ms(m->start), m->whoami);
		if (set_last_meal(m) == false)
			return (false);
		usleep(m->set[EAT] * 1000);
	}
	return (true);
}

void	*daily(void *ref)
{
	t_mind	*m;

	m = (t_mind *)ref;
	m->meals = 0;
	while (1)
	{
		printf(THNK, fast_ms(m->start), m->whoami);
		if (grab(m) == false)
			return ((void *)false);
		// pthread_mutex_lock(m->inspec);
		// usleep seems better
		// 1000 maybe
		// this defo looks more precise and safe
		printf(THNK, fast_ms(m->start), m->whoami);
		if (m->whoami % 2)
			usleep(m->set[REST] * 1000);
		else
			usleep(m->set[REST] * 1000 + 100);
		// fast_wait(100);
	}
	return ((void *)false);
}
