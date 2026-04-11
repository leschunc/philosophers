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

enum					e_attr
{
	NUM,
	DIE,
	EAT,
	REST,
	CYCLE
};

typedef pthread_mutex_t	mut_t;

typedef struct s_mind
{
	int					whoami;
	long				*set;
	long				meals;
	mut_t				*inspec;
	suseconds_t			start;
	// int				mode;
	long				last_meal;
	mut_t				*r_fork;
	mut_t				*l_fork;
}						t_mind;

typedef struct s_context
{
	// int				mode;
	long				*set;
	suseconds_t			start;
	pthread_t			*philo;
	t_mind				*mind;
	mut_t				*fork;
	mut_t				*inspec;
	int					arr_len;
	char const			**argv;
	int					ite;
}						t_context;

/* parse */
void					atoiv(t_context c);
void					disp_args(t_context c);

/* init */
bool					init(t_context *c);
bool					init_fork(t_context *c);
bool					init_sim(t_context *c);
bool					init_monitor(t_context *c);

/* philos */
bool					grab(t_mind *m);
void					drop(t_mind m);
void					*daily(void *ref);

/* monitor */
void					*fate(void *ref);

/* clock */
void					fast_wait(long wait);
suseconds_t				get_time(suseconds_t start);
suseconds_t				get_start(void);

/* utils */
void					safe_free(char **ptr);

#endif