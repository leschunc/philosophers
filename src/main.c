#include "philo.h"

int	main(int argc, char const *argv[])
{
	t_context	c;
	int			set[5];

	if (argc != 5 && argc != 6)
		return (ERR);
	c.arr_len = argc - 1;
	c.argv = argv;
	c.set = set;
	atoiv(c);
	if (c.set[NUM] == 1)
	{
		// kill_thisguy();
		return (ERR);
	}
	if (prepare_sim(c) != OK)
		return (OK);
	// run_simulation();
	return (ERR);
}
