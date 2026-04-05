#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

# define EMPTY '\0'
# define OKAY 0
// # define NOT_OK !
# define S_NUM "number_of_philosophers"
# define S_DIE "time_to_die"
# define S_EAT "time_to_eat"
# define S_REST "time_to_sleep"
# define S_CYCLE "number_of_times_each_philosopher_must_eat"

enum	e_attr
{
	NUM,
	DIE,
	EAT,
	REST,
	CYCLE
};

/* parse */
void	atoiv(int argc, char const *argv[], int *set);
void	disp_args(int argc, int *set);

/* init */
bool	prepare_sim(int *set);
bool    init_mutexes(int *set, pthread_mutex_t *mut_arr);

/* philos */

/* monitor */

/* utils */
void	safe_free(char **ptr);

#endif