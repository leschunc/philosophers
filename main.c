#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t	turn;

int				gold;

void	*steal(void *arg)
{
	int	knowledge;
	int	amount_stolen;

	knowledge = 0;
	amount_stolen = 0;
	while (knowledge >= 0)
	{
		pthread_mutex_lock(&turn);
		gold--;
		knowledge = gold;
		amount_stolen++;
		pthread_mutex_unlock(&turn);
		usleep(1);
	}
	printf("amount stolen %d\n", amount_stolen);
}

void	*earn(void *arg)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&turn);
		gold++;
		pthread_mutex_unlock(&turn);
		usleep(100);
	}
}

int	main(int argc, char const *argv[])
{
	pthread_t	thief;
	pthread_t	worker;

	gold = 0;
	pthread_mutex_init(&turn, NULL);
	pthread_create(&thief, 0, earn, 0);
	pthread_create(&worker, 0, steal, 0);
	pthread_join(thief, NULL);
	pthread_join(worker, NULL);
	pthread_mutex_destroy(&turn);
	puts("");
	return (0);
}
