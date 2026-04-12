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
