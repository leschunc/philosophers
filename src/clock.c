#include "philo.h"

void	fast_ahh_wait(long wait)
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
		// magic number for luck
		// usleep(set[NUM] / 3);
	}
}

suseconds_t	get_time(void)
{
	struct timeval	now;
	suseconds_t		u_time;

	gettimeofday(&now, NULL);
	u_time = now.tv_sec * 1000000;
	u_time += now.tv_usec;
	return (u_time);
}

