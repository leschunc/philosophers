#include "philo.h"

int	main(int argc, char const *argv[])
{
	int	set[5];
	int	arg_num;

	arg_num = argc - 1;
	if (arg_num != 4)
		return (1);
	atoiv(arg_num, argv + 1, set);
	disp_args(arg_num, set);
	prepare_sim(arg_num, set);
	// run_simulation();
}
