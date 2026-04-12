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
	int		i;
	t_mind	mind[SIM_SIZE];

	c->mind = mind;
	i = 0;
	give_free_will(c);
	while (i < c->set[NUM])
	{
		if (pthread_create(c->philo + i, NULL, daily, mind + i) != OK)
			return (false);
		i++;
	}
	if (init_monitor(c) == false)
		return (false);
	i = 0;
	while (i < c->set[NUM])
	{
		if (pthread_join(c->philo[i], NULL) != OK)
			return (false);
		i++;
	}
	return (true);
}

void	destroy_mutx(t_mut *fork, t_mut *inspec, long *info)
{
	int	i;

	i = 0;
	while (i < info[NUM])
	{
		if (pthread_mutex_destroy(fork + i) == EBUSY)
			// this is not gonna happen
			ft_putstr_fd("EBUSY fork\n", 2);
		i++;
	}
	i = 0;
	if (info[CYC] == 0)
		return ;
	while (i < info[NUM])
	{
		// unlock(inspec + i);
		if (pthread_mutex_destroy(inspec + i) == EBUSY)
			// this is not gonna happen
			ft_putstr_fd("EBUSY inspec\n", 2);
		i++;
	}
}

bool	init_monitor(t_context *c)
{
	pthread_t	determinism;

	pthread_create(&determinism, NULL, fate, c);
	pthread_join(determinism, NULL);
	return (true);
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
		return (false);
	if (inspec_init(c) == false)
		return (false);
	if (init_sim(c) == false)
		return (false);
	destroy_mutx(fork, inspec, c->set);
	return (true);
}
