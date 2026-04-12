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

	if (m)
	{
		// lock(m->inspec);
		if (killed(m) == false)
			printf(msgs[num], get_time(m->start), m->whoami);
		// unlock(m->inspec);
	}
	else
	{
		printf(msgs[num], get_time(c->start), i);
	}
}
