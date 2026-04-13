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
	if (atoiv(&c) == ERR)
		return (ERR);
	if (init(&c) == true)
		return (OK);
	return (ERR);
}
