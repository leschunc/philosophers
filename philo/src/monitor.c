#include "philo.h"

void	turn_minds_off(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->set[NUM])
	{
		lock(c->inspec + i);
		c->mind[i].last_meal = -1;
		unlock(c->inspec + i);
		i++;
	}
}

bool	safe_inspec(t_context *c, int i)
{
	static int	finished = 0;
	suseconds_t	now;

	now = get_time(c->start);
	lock(c->inspec + i);
	if (c->mind[i].meals > 0 && c->set[CYC] == c->mind[i].meals)
	{
		finished++;
		if (finished == c->set[NUM])
		{
			unlock(c->inspec + i);
			return (false);
		}
	}
	else if (now - c->mind[i].last_meal >= c->set[DIE])
	{
		msg(DIED, NULL, c, i);
		unlock(c->inspec + i);
		turn_minds_off(c);
		return (false);
	}
	unlock(c->inspec + i);
	return (true);
}

void	*fate(void *ref)
{
	t_context	*c;
	int			i;

	c = ref;
	while (1)
	{
		i = 0;
		while (i < c->set[NUM])
		{
			if (safe_inspec(c, i) == false)
				return (NULL);
			usleep(0);
			i++;
		}
	}
	return (NULL);
}
