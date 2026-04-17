/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:29:41 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/17 18:30:28 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_abort(t_context *c, int limit)
{
	int	i;

	i = 0;
	c->simulation = false;
	unlock(&c->broadcast);
	while (i < limit)
	{
		pthread_join(c->philo[i], 0);
		i++;
	}
}

void	join_exit(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->set[NUM])
	{
		pthread_join(c->philo[i], 0);
		i++;
	}
}
