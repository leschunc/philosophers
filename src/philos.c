#include "philo.h"

void	grab(t_mind m)
{
	// struct timeval	now;
	if (m.whoami % 2 == 0)
	{
		pthread_mutex_lock(m.l_fork);
		// gettimeofday(&now, NULL);
		// printf("%ld got left fork\n", now.tv_usec);
		pthread_mutex_lock(m.r_fork);
		// gettimeofday(&now, NULL);
		// printf("%ld got right fork\n", now.tv_usec);
	}
	else
	{
		pthread_mutex_lock(m.r_fork);
		// gettimeofday(&now, NULL);
		// printf("%ld got right fork\n", now.tv_usec);
		pthread_mutex_lock(m.l_fork);
		// gettimeofday(&now, NULL);
		// printf("%ld got left fork\n", now.tv_usec);
	}
}

void	drop(t_mind m)
{
	// put this inside of mind
	// struct timeval	now;
	// printf("%d free right fork: %p\n", m.whoami, m.r_fork);
	// printf("%d free left fork: %p\n", m.whoami, m.l_fork);
	// printf("releasing both\n\n");
	pthread_mutex_unlock(m.r_fork);
	pthread_mutex_unlock(m.l_fork);
	// gettimeofday(&now, NULL);
	// printf("%ld got left fork\n", now.tv_usec);
}

void	*daily(void *ref)
{
	t_mind	*m;

	m = (t_mind *)ref;
	m->meals = 0;
	while (1)
	{
		grab(*m);
		printf("%d in grab\n", m->whoami);
		drop(*m);
		pthread_mutex_lock(m->inspec);
		if (m->set[CYCLE])
		{
			printf("%d meals %ld cyc %ld\n", m->whoami, m->meals,
				m->set[CYCLE]);
			if (m->meals == m->set[CYCLE])
			{
				printf("%d if meal hits target\n", m->whoami);
				return (pthread_mutex_unlock(m->inspec), NULL);
			}
			(m->meals)++;
		}
		pthread_mutex_unlock(m->inspec);
		// usleep seems better
		// usec_wait(1000);
		// 1000 maybe
		usleep(999);
	}
	return (NULL);
}
