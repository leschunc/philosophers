#include "philo.h"

void	usec_wait(long wait)
{
	struct timeval	now;
	long			init;

	gettimeofday(&now, NULL);
	init = now.tv_sec * 1000000 + now.tv_usec;
	while (1)
	{
		gettimeofday(&now, NULL);
		if (now.tv_sec * 1000000 + now.tv_usec - init >= wait)
			break ;
		// usleep(10);
	}
	// printf("%ld\n", now.tv_sec * 1000000 + now.tv_usec - init);
}
