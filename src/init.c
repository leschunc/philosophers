#include "philo.h"

bool	init_fork(t_context c)
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

bool	inspec_init(t_context c)
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

void	give_free_will(t_context c)
{
	int	i;

	i = 0;
	while (i < c.set[NUM])
	{
		c.mind[i].whoami = i;
		c.mind[i].inspec = c.inspec + i;
		c.mind[i].r_fork = c.fork + i;
		c.mind[i].meals = 0;
		c.mind[i].set = c.set;
		if (i == 0)
			c.mind[i].l_fork = &c.fork[c.set[NUM] - 1];
		else
			c.mind[i].l_fork = &c.fork[i - 1];
		i++;
	}
	i = 0;
	c.start_time = get_time();
	while (i < c.set[NUM])
	{
		c.mind[i].start_time = c.start_time;
		i++;
	}
}

bool	init_sim(t_context c)
{
	int		i;
	t_mind	mind[c.set[NUM]];

	c.mind = mind;
	i = 0;
	give_free_will(c);
	while (i < c.set[NUM])
	{
		if (pthread_create(c.philo + i, NULL, daily, mind + i) != OK)
			return (false);
		i++;
	}
	i = 0;
	while (i < c.set[NUM])
	{
		if (pthread_join(c.philo[i], NULL) != OK)
			return (false);
		i++;
	}
	return (true);
}

void	destroy_mutx(mut_t *fork, mut_t *inspec, long *info)
{
	int	i;

	i = 0;
	while (i < info[NUM])
	{
		if (pthread_mutex_destroy(fork + i) == EBUSY)
			// this is not gonna happen
			ft_putstr_fd("EBUSY\n", 2);
		i++;
	}
	i = 0;
	if (info[CYCLE] == 0)
		return ;
	while (i < info[NUM])
	{
		// pthread_mutex_unlock(inspec + i);
		if (pthread_mutex_destroy(inspec + i) == EBUSY)
			// this is not gonna happen
			ft_putstr_fd("EBUSY\n", 2);
		i++;
	}
	ft_putstr_fd("SEEMS FINE\n", 2);
}

bool	init(t_context c)
{
	pthread_t	philo[c.set[NUM]];
	mut_t		fork[c.set[NUM]];
	mut_t		inspec[c.set[NUM]];

	// what if its zero
	// memset(fork, 0, sizeof(mut_t) * c.set[NUM]);
	// memset(philo, 0, sizeof(pthread_t) * c.set[NUM]);
	c.philo = philo;
	c.fork = fork;
	c.inspec = inspec;
	// c.meals = meals;
	// memset(inspec, 0, sizeof(mut_t) * c.set[NUM]);
	if (init_fork(c) == false)
		return (false);
	if (inspec_init(c) == false)
		return (false);
	if (init_sim(c) == false)
		return (false);
	// memset0 mutx and then destroy all that are nonzero
	destroy_mutx(fork, inspec, c.set);
	return (true);
}
