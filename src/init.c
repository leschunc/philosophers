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

void	*dont(void *ref)
{
	t_context	*deref;
	t_context	c;

	deref = ref;
	c = *deref;
	pthread_mutex_lock(&c.fork[c.ite]);
	printf("hi! im %d\n\n", c.ite);
	// sleep(1);
	// sleep(1);
	pthread_mutex_unlock(&c.fork[c.ite]);
	return (NULL);
}

bool	init_philos(t_context c)
{
	c.ite = 0;
	while (c.ite < c.set[NUM])
	{
		if (pthread_create(c.philo + c.ite, NULL, dont, &c) != OK)
			return (false);
		if (pthread_join(*(c.philo + c.ite), NULL) != OK)
			return (false);
		c.ite++;
	}
	return (true);
}

void	destroy_mutx(pthread_mutex_t *fork, int *info)
{
	int	i;

	i = 0;
	while (i < info[NUM])
	{
		pthread_mutex_destroy(fork + i);
		i++;
	}
}

bool	prepare_sim(t_context c)
{
	pthread_mutex_t	fork[c.set[NUM]];
	pthread_t		philo[c.set[NUM]];

	c.fork = fork;
	c.philo = philo;
	// if (c.arr_len == 4)
	// 	printf("[4]\t[arguments]\n\n");
	// disp_args(c);
	if (init_forks(c) == false)
		return (false);
	if (init_philos(c) == false)
		return (false);
	destroy_mutx(fork, c.set);
	return (true);
}
