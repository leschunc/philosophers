#include "philo.h"

pthread_mutex_t	turn;

void	*steal(void *arg)
{
	int	i;

	i = 10;
	(void)arg;
	while (i--)
	{
		pthread_mutex_lock(&turn);
		printf("ive stolen\n");
		pthread_mutex_unlock(&turn);
		usleep(100);
	}
	return (NULL);
}

void	init(void)
{
	pthread_t	thief;

	pthread_mutex_init(&turn, NULL);
	pthread_create(&thief, NULL, steal, NULL);
	pthread_join(thief, NULL);
	pthread_mutex_destroy(&turn);
}

int	main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	init();
	return (0);
}
