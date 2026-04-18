/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:45:19 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/18 14:45:27 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg_helper(suseconds_t time, int philo, int msg_i)
{
	static char	*msgs[] = {MSG1, MSG2, MSG3, MSG4, MSG5, MSG6, E_MANY, E_MURD};

	putn_buf(time);
	ft_putstr("\t");
	putn_buf(philo);
	ft_putstr("\t");
	ft_putstr(msgs[msg_i]);
}

void	msg(int num, t_mind *m, t_context *c, int i)
{
	if (m)
	{
		if (killed(m) == false)
		{
			lock(m->broadcast);
			if (m->simulation[0] == true)
				msg_helper(get_time(m->start[0]), m->whoami + 1, num);
			unlock(m->broadcast);
		}
	}
	else
	{
		lock(&c->broadcast);
		msg_helper(get_time(c->start), i + 1, num);
		unlock(&c->broadcast);
	}
}
