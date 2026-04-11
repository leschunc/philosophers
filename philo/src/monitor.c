#include "philo.h"

void	*fate(void *ref)
{
	t_context	*c;
	suseconds_t	now;
	int			i;

	c = ref;
	i = 0;
	while (1)
	{
		if (i < c->set[NUM])
		{
			now = get_time(c->start);
			pthread_mutex_lock(c->inspec + i);
			if (now - c->mind[i].last_meal > c->set[DIE])
			{
				if (c->mind[i].last_meal != -1)
				{
					printf("monitor: philo died [%d]\n", i);
					c->mind[i].last_meal = -1;
					if (c->set[NUM] == 1)
					{
						pthread_mutex_unlock(c->inspec + i);
						return (NULL);
					}
				}
			}
			pthread_mutex_unlock(c->inspec + i);
			// printf("now %ld lm %ld dif %ld TDIE %ld\n", now,
			// 	c->mind[i].last_meal, now - c->mind[i].last_meal, c->set[DIE]);
			usleep(20000);
			// usleep(50);
			i++;
		}
		else
			i = 0;
	}
	return (NULL);
}
