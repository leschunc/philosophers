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

void	grab_right(t_context c)
{
	printf("%d grab right fork: %d\n", c.ite, c.ite);
	pthread_mutex_lock(&c.fork[c.ite]);
}

void	free_right(t_context c)
{
	printf("%d free right fork: %d\n", c.ite, c.ite);
	pthread_mutex_unlock(&c.fork[c.ite]);
}

void	grab_left(t_context c)
{
	if (c.ite == 0)
	{
		printf("%d grab left fork: %d\n", c.ite, c.set[NUM - 1]);
		pthread_mutex_lock(&c.fork[c.set[NUM - 1]]);
	}
	else
	{
		printf("%d grab left fork: %d\n", c.ite, c.ite - 1);
		pthread_mutex_lock(&c.fork[c.ite - 1]);
	}
}

void	free_left(t_context c)
{
	if (c.ite == 0)
	{
		printf("%d grab left fork: %d\n", c.ite, c.set[NUM - 1]);
		pthread_mutex_unlock(&c.fork[c.set[NUM - 1]]);
	}
	else
	{
		printf("%d grab left fork: %d\n", c.ite, c.ite - 1);
		pthread_mutex_unlock(&c.fork[c.ite - 1]);
	}
}

void	*dont(void *ref)
{
	t_context	c;

	c = *(t_context *)ref;
	grab_right(c);
	// grab_left(c);
	printf("hi\n");
	// free_left(c);
	free_right(c);
	sleep(1);
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
		mind[i].r_fork = &c.fork[i];
		if (i == 0)
			mind[i].l_fork = &c.fork[c.set[NUM] - 1];
		else
			mind[i].l_fork = &c.fork[i - 1];
		i++;
	}

	// i = 0;
	// while (i < c.set[NUM])
	// {
	// 	// printf("to init [%d]\n", i);
	// 	if (pthread_create(c.philo + i, NULL, dont, &c) != OK)
	// 		return (false);
	// 	i++;
	// }
	// i = 0;
	// while (i < c.set[NUM])
	// {
	// 	if (pthread_join(*(c.philo + i), NULL) != OK)
	// 		return (false);
	// 	i++;
	// }
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

	// memset(fork, 0, sizeof(pthread_mutex_t) * c.set[NUM]);
	// memset(philo, 0, sizeof(pthread_t) * c.set[NUM]);
	c.fork = fork;
	c.philo = philo;
	if (init_forks(c) == false)
		return (false);
	if (init_philos(c) == false)
		return (false);
	destroy_mutx(fork, c.set);
	return (true);
}
