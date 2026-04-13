/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:15 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/13 23:42:09 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool	init(t_context *c)
{
	pthread_t	philo[SIM_SIZE];
	t_mut		fork[SIM_SIZE];
	t_mut		inspec[SIM_SIZE];

	c->philo = philo;
	c->fork = fork;
	c->inspec = inspec;
	c->simulation[0] = true;
	if (pthread_mutex_init(c->broadcast, NULL) != OK)
		return (false);
	if (init_fork(c) == false)
		return (false);
	if (inspec_init(c) == false)
		return (false);
	if (init_sim(c) == false)
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_context	c;
	static long	set[5];

	if (argc != 5 && argc != 6)
		return (ERR);
	c.arr_len = argc - 1;
	c.argv = argv;
	c.set = set;
	if (atoiv(&c) == ERR)
		return (ERR);
	if (init(&c) == true)
		return (OK);
	return (ERR);
}
