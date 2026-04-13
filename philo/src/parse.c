#include "philo.h"

int	cmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
		(s1++, s2++);
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	pre_check(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		if (ft_strlen(str) > 10)
			return (false);
		if (ft_strlen(str) == 10)
		{
			
			if (cmp(str, "2147483647") > 0)
			{
				printf("hi\n");
				return (false);
			}
		}
		while (str[i])
		{
			if (ft_isdigit(str[i]) == false)
				return (false);
			i++;
		}
	}
	return (true);
}

bool	atoiv(t_context *c)
{
	int			i;
	suseconds_t	start;

	i = 0;
	while (i < c->arr_len)
	{
		if (pre_check(c->argv[i + 1]) == false)
		{
			printf("Digit only integers up to 2,147,483,647 allowed\n");
			return (ERR);
		}
		c->set[i] = atonum(c->argv[i + 1]);
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
		return (printf(ERR1, c->set[NUM]), ERR);
	return (OK);
}
