#include "philo.h"

bool	atoiv(t_context *c)
{
	int			i;
	suseconds_t	start;

	i = 0;
	while (i < c->arr_len)
	{
		c->set[i] = ft_atoi(c->argv[i + 1]);
		i++;
	}
	if (c->set[NUM] == 1)
	{
		start = get_start();
		usleep(c->set[DIE] * 1000);
		printf(ERR2, get_time(start));
		return (ERR);
	}
	if (c->set[NUM] > 4000)
	{
		printf(ERR1, c->set[NUM]);
		return (ERR);
	}
	return (OK);
}
