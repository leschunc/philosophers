#include "philo.h"

int	main(int argc, char const *argv[])
{
	t_context	c;
	static long	set[5];

	if (argc != 5 && argc != 6)
		return (ERR);
	c.arr_len = argc - 1;
	c.argv = argv;
	c.set = set;
	atoiv(&c);
	if (init(&c) == true)
	{
		destroy_mutx(&c);
		return (OK);
	}
	destroy_mutx(&c);
	return (ERR);
}
