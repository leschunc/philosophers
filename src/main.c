#include "philo.h"

int	main(int argc, char const *argv[])
{
	int	context[5];
	int	a_len;

	a_len = argc - 1;
	if (a_len != 4)
		return (1);
	atoiv(a_len, argv + 1, context);
	disp_args(a_len, context);
	if (prepare_sim(context) != OKAY)
		return (1);
	// run_simulation();
}
