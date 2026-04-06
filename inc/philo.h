#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

# define EMPTY '\0'
# define OK 0
# define ERR 1
// # define NOT_OK !
# define S_NUM "number_of_philosophers"
# define S_DIE "time_to_die"
# define S_EAT "time_to_eat"
# define S_REST "time_to_sleep"
# define S_CYCLE "number_of_times_each_philosopher_must_eat"

enum				e_attr
{
	NUM,
	DIE,
	EAT,
	REST,
	CYCLE
};

typedef struct s_context
{
	int				*set;
	// int				mode;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	int				arr_len;
	char const		**argv;
	int				ite;
}					t_context;

/* parse */
void				atoiv(t_context c);
void				disp_args(t_context c);

/* init */
bool				prepare_sim(t_context c);
bool				init_forks(t_context c);
bool				init_philos(t_context c);

/* philos */

/* monitor */

/* utils */
void				safe_free(char **ptr);

#endif