#include "philo.h"

bool	init_forks(t_context c)
{
	int	i;

	i = 0;
	while (i < c.set[NUM])
	{
		if (pthread_mutex_init(c.fork + i, NULL) != OK)
			return (false);
		i++;
	}
	return (true);
}

bool	init_inspec(t_context c)
{
	int	i;

	i = 0;
	while (i < c.set[NUM])
	{
		if (pthread_mutex_init(c.inspec + i, NULL) != OK)
			return (false);
		i++;
	}
	return (true);
}

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
	t_mind	m;

	m = *(t_mind *)ref;
	while (1)
	{
		grab(m);
		printf("%d\n", m.whoami);
		drop(m);
		// usleep seems better
		// usec_wait(1000);
		// 1000 maybe
		usleep(999);
	}
	return (NULL);
}

bool	init_philos(t_context c)
{
	int		i;
	t_mind	mind[c.set[NUM]];

	i = 0;
	while (i < c.set[NUM])
	{
		mind[i].whoami = i;
		// mind[i].
		mind[i].r_fork = &c.fork[i];
		if (i == 0)
			mind[i].l_fork = &c.fork[c.set[NUM] - 1];
		else
			mind[i].l_fork = &c.fork[i - 1];
		i++;
	}
	i = 0;
	while (i < c.set[NUM])
	{
		// printf("to init [%d]\n", i);
		if (pthread_create(c.philo + i, NULL, daily, mind + i) != OK)
			return (false);
		i++;
	}
	i = 0;
	while (i < c.set[NUM])
	{
		if (pthread_join(*(c.philo + i), NULL) != OK)
			return (false);
		// printf("here too\n");
		i++;
	}
	return (true);
}

void	destroy_mutx(pthread_mutex_t *fork, int *info)
{
	int	i;

	i = 0;
	while (i < info[NUM])
	{
		if (pthread_mutex_destroy(fork + i) == EBUSY)
			// this is not gonna happen
			printf("EBUSY\n");
		// printf("aqui\n");
		i++;
	}
}

bool	prepare_sim(t_context c)
{
	pthread_t		philo[c.set[NUM]];
	pthread_mutex_t	fork[c.set[NUM]];
	pthread_mutex_t	inspec[c.set[NUM]];

	// memset(fork, 0, sizeof(pthread_mutex_t) * c.set[NUM]);
	// memset(philo, 0, sizeof(pthread_t) * c.set[NUM]);
	c.philo = philo;
	c.fork = fork;
	c.inspec = inspec;
	// c.meals = meals;
	// memset(inspec, 0, sizeof(pthread_mutex_t) * c.set[NUM]);
	if (init_forks(c) == false)
		return (false);
	if (init_inspec(c) == false)
		return (false);
	if (init_philos(c) == false)
		return (false);
	// memset0 mutx and then destroy all that are nonzero
	destroy_mutx(fork, c.set);
	return (true);
}
