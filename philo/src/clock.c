#include "philo.h"

bool	am_i_dead_wait(t_mind *m, long wait)
{
	struct timeval	now;
	long			init;

	gettimeofday(&now, NULL);
	init = now.tv_sec * 1000000 + now.tv_usec;
	while (1)
	{
		gettimeofday(&now, NULL);
		if (i_am_dead(m))
			return (true);
		if (now.tv_sec * 1000000 + now.tv_usec - init >= wait)
			break ;
		usleep(1000);
	}
	return (false);
}

suseconds_t	get_time(suseconds_t start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000000 + now.tv_usec - start) / 1000);
}

suseconds_t	get_start(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000000 + now.tv_usec);
}
