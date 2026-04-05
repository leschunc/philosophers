#include "philo.h"

bool	is_valid_arg(int argc, char const *argv[])
{
	int	i;

	i = ft_atoi("123");
	printf("%d\n", i);
	// checking minimum amount of arguments
	if (argc != 5 && argc != 6)
		return (NULL);
	i = 0;
	// checks if arguments arent empty
	while (argv[i])
	{
		if (argv[i][0] == EMPTY_ARG)
			return (false);
		if (argv[i][0])
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char const *argv[])
{
	if (is_valid_arg(argc, argv))
		printf("ok\n");
	else
		printf("Nok\n");
}
