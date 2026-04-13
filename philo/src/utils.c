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
	static char	*msgs[] = {MSG1, MSG2, MSG3, MSG4, MSG5, ERR1, ERR2};
	suseconds_t	now;

	if (m)
		now = get_time(m->start);
	else
		now = get_time(c->start);
	if (m)
	{
		if (killed(m) == false)
			printf(msgs[num], now, m->whoami + 1);
	}
	else
	{
		usleep(3e3);
		printf(msgs[num], now, i + 1);
	}
}

int	ft_isspace(char c)
{
	if (((c >= 9) && (c <= 13)) || (c == ' '))
	{
		return (1);
	}
	return (0);
}

int	ft_isdigit(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
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
