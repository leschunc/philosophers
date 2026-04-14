/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:53:12 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/14 02:45:14 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(char c)
{
	if (((c >= 9) && (c <= 13)) || (c == ' '))
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	atonum(const char *nptr)
{
	char	*ptr;
	int		result;
	int		sl;

	result = 0;
	sl = 1;
	ptr = (char *)nptr;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sl = -1;
		ptr++;
	}
	while (ft_isdigit(*ptr))
	{
		result = (result * 10) + (*ptr - '0');
		ptr++;
	}
	return (result * sl);
}

bool	killed(t_mind *m)
{
	lock(m->inspec);
	if (m->last_meal == -1)
	{
		unlock(m->inspec);
		return (true);
	}
	unlock(m->inspec);
	return (false);
}

long	pos(long num)
{
	if (num < 0)
		return (-num);
	return (num);
}
