#ifndef PHILO_H
# define PHILO_H

// self explanatory review to remove functions that are forbidden
# include "libft.h"
// for the main thread functions
# include <pthread.h>
// for true and false
# include <stdbool.h>
// for memset
# include <string.h>
// for gettimeofday
# include <sys/time.h>
// for EBUSY for example
# include <errno.h>

// for printf remove this to deliver
# include <stdio.h>

# define EMPTY '\0'
# define ERR 1
# define OK 0
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
	// int				mode;
	int				*set;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*inspec;
	int				arr_len;
	char const		**argv;
	int				ite;
}					t_context;

typedef struct s_mind
{
	int				whoami;
	int				*set;
	long			meals;
	pthread_mutex_t	*inspec;
	// int				arr_len;
	// int				mode;

	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_mind;

/* parse */
void				atoiv(t_context c);
void				disp_args(t_context c);

/* init */
bool				prepare_sim(t_context c);
bool				init_forks(t_context c);
bool				init_philos(t_context c);

/* philos */

/* monitor */

/* clock */
void				usec_wait(long wait);

/* utils */
void				safe_free(char **ptr);

#endif