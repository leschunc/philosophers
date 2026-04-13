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
			printf(msgs[num], now, m->whoami);
	}
	else
	{
		usleep(3e3);
		printf(msgs[num], now, i);
	}
}
