#include "philo.h"

bool	init_fork(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->set[NUM])
	{
		if (pthread_mutex_init(c->fork + i, NULL) != OK)
			return (false);
		i++;
	}
	return (true);
}

bool	inspec_init(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->set[NUM])
	{
		if (pthread_mutex_init(c->inspec + i, NULL) != OK)
			return (false);
		i++;
	}
	return (true);
}

void	give_free_will(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->set[NUM])
	{
		c->mind[i].whoami = i;
		c->mind[i].inspec = c->inspec + i;
		c->mind[i].r_fork = c->fork + i;
		c->mind[i].meals = 0;
		c->mind[i].last_meal = 0;
		c->mind[i].set = c->set;
		if (i == 0)
			c->mind[i].l_fork = &c->fork[c->set[NUM] - 1];
		else
			c->mind[i].l_fork = &c->fork[i - 1];
		i++;
	}
	i = 0;
	c->start = get_start();
	while (i < c->set[NUM])
	{
		c->mind[i].start = c->start;
		i++;
	}
}

bool	init_sim(t_context *c)
{
	int			i;
	t_mind		mind[SIM_SIZE];
	pthread_t	determinism;

	c->mind = mind;
	i = 0;
	give_free_will(c);
	if (pthread_create(&determinism, NULL, fate, c) != OK)
		return (false);
	while (i < c->set[NUM])
	{
		if (pthread_create(c->philo + i, NULL, daily, mind + i) != OK)
			return (false);
		i++;
	}
	pthread_join(determinism, NULL);
	i = 0;
	while (i < c->set[NUM])
	{
		if (pthread_join(c->philo[i], NULL) != OK)
			return (false);
		i++;
	}
	return (true);
}

void	destroy_mutx(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->set[NUM])
	{
		pthread_mutex_destroy(c->fork + i);
		i++;
	}
	i = 0;
	if (c->set[CYC] == 0)
		return ;
	while (i < c->set[NUM])
	{
		pthread_mutex_destroy(c->inspec + i);
		i++;
	}
}

bool	init(t_context *c)
{
	pthread_t	philo[SIM_SIZE];
	t_mut		fork[SIM_SIZE];
	t_mut		inspec[SIM_SIZE];

	c->philo = philo;
	c->fork = fork;
	c->inspec = inspec;
	if (init_fork(c) == false)
		return (destroy_mutx(c), false);
	if (inspec_init(c) == false)
		return (destroy_mutx(c), false);
	if (init_sim(c) == false)
		return (destroy_mutx(c), false);
	return (destroy_mutx(c), true);
}
