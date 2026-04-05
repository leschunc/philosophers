#include "philo.h"

bool	init_mutexes(int *context, pthread_mutex_t *mut_arr)
{
	int	i;

	i = 0;
	while (i < context[NUM])
	{
		if (pthread_mutex_init(mut_arr + i, NULL) != OKAY)
			return (false);
		i++;
	}
	return (true);
}

bool	prepare_sim(int *context)
{
	pthread_mutex_t	mut_arr[context[0]];

	if (init_mutexes(context, mut_arr) != OKAY)
		return (false);
	
	return (true);
}
