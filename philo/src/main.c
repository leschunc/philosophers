/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:15 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/17 17:01:21 by leschunc         ###   ########.fr       */
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

void	free_loop(t_context *c, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		pthread_join(*c->philo + i, 0);
		i++;
	}
}

bool	init_sim(t_context *c)
{
	int			i;
	t_mind		mind[SIM_MAX];
	pthread_t	determinism;

	c->mind = mind;
	i = 0;
	(give_free_will(c), lock(&c->broadcast));
	while (i < c->set[NUM])
	{
		if (pthread_create(c->philo + i, NULL, daily, mind + i) != OK)
			break ;
		i++;
	}
	if (i < c->set[NUM])
		return (free_loop(c, i), false);
	if (pthread_create(&determinism, NULL, fate, c) != OK)
		return (pthread_join(determinism, 0), false);
	c->start = get_start();
	(unlock(&c->broadcast), pthread_join(determinism, NULL));
	i = 0;
	while (i++ < c->set[NUM])
		if (pthread_join(c->philo[i], NULL) != OK)
			return (false);
	return (true);
}

bool	init(t_context *c)
{
	pthread_t	philo[SIM_MAX];
	t_mut		fork[SIM_MAX];
	t_mut		inspec[SIM_MAX];

	if (c->set[NUM] == 1)
		return (one_lonely_philo(c));
	c->philo = philo;
	c->fork = fork;
	c->inspec = inspec;
	c->simulation = true;
	if (pthread_mutex_init(&c->broadcast, NULL) != OK)
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
	static int	set[5];

	if (argc != 5 && argc != 6)
	{
		printf("4 or 5 arguments required\n");
		return (ERR);
	}
	c.arr_len = argc - 1;
	c.argv = argv;
	c.set = set;
	if (atoiv(&c) == ERR)
		return (ERR);
	if (init(&c) == true)
		return (OK);
	return (ERR);
}

// void	infinite_mutx_glitch(void)
// {
// 	t_mut	fork[20000];
// 	static int		i;

// 	i++;
// 	printf("%d\n", i);
// 	fflush(stdout);
// 	while (i < 20000)
// 	{
// 		pthread_mutex_init(fork + i, 0);
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	while (1)
// 	{
// 		infinite_mutx_glitch();
// 	}
// 	return (0);
// }
