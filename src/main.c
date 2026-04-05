#include "philo.h"

bool	is_valid_arg(int argc, char const *argv[])
{
	int	i;

	i = ft_atoi("hello");
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

// pthread_mutex_t	turn;

// void	*steal(void *arg)
// {
// 	int	i;

// 	i = 10;
// 	(void)arg;
// 	while (i--)
// 	{
// 		pthread_mutex_lock(&turn);
// 		printf("ive stolen\n");
// 		pthread_mutex_unlock(&turn);
// 		usleep(100);
// 	}
// 	return (NULL);
// }

// void	init(void)
// {
// 	pthread_t	thief;

// 	pthread_mutex_init(&turn, NULL);
// 	pthread_create(&thief, NULL, steal, NULL);
// 	pthread_join(thief, NULL);
// 	pthread_mutex_destroy(&turn);
// }
