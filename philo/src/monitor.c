#include "philo.h"

void	turn_minds_off(t_context *c, int ite)
{
	int	i;

	i = 0;
	while (i < c->set[NUM])
	{
		if (i == ite)
		{
			i++;
			continue ;
		}
		pthread_mutex_lock(c->inspec + i);
		c->mind[i].last_meal = -1;
		pthread_mutex_unlock(c->inspec + i);
		i++;
	}
}

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
				// where
				printf(DIED, get_time(c->mind[i].start),
					c->mind[i].whoami);
				turn_minds_off(c, i);
				pthread_mutex_unlock(c->inspec + i);
				return (NULL);
			}
			pthread_mutex_unlock(c->inspec + i);
			// printf("now %ld lm %ld dif %ld TDIE %ld\n", now,
			// 	c->mind[i].last_meal, now - c->mind[i].last_meal, c->set[DIE]);
			usleep(1000);
			// usleep(50);
			i++;
		}
		else
			i = 0;
	}
	return (NULL);
}
