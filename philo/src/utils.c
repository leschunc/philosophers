/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:25 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/17 14:07:26 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	unlock(t_mut *mut)
{
	pthread_mutex_unlock(mut);
}

void	lock(t_mut *mut)
{
	pthread_mutex_lock(mut);
}

void	msg(int num, t_mind *m, t_context *c, int i)
{
	static char	*msgs[] = {MSG1, MSG2, MSG3, MSG4, MSG5, MSG6, ER_MANY, ER_MURDERED};

	if (m)
	{
		if (killed(m) == false)
		{
			lock(m->broadcast);
			if (m->simulation[0] == true)
				printf(msgs[num], get_time(m->start[0]), m->whoami + 1);
			unlock(m->broadcast);
		}
	}
	else
	{
		lock(&c->broadcast);
		printf(msgs[num], get_time(c->start), i + 1);
		unlock(&c->broadcast);
	}
}
