#ifndef PHILO_H
# define PHILO_H

// remove libft
# include "libft.h"
# include <errno.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>

# define EMPTY '\0'
# define ERR 1
# define OK 0
# define SIM_SIZE 4000

# define FORK "%5ld\t%3d\thas taken a fork\n"
# define EATS "%5ld\t%3d\tis eating\n"
# define NAPS "%5ld\t%3d\tis sleeping\n"
# define THNK "%5ld\t%3d\tis thinking\n"
# define DIED "%5ld\t%3d\thas died\n"

# define SHAME "%5ld 0 has died \033[31mbecause of YOU\033[0m\n"
# define STOP "\033[31mCAPTCHA\033[0m: name all %ld philosophers\n"

enum					e_attr
{
	NUM,
	DIE,
	EAT,
	REST,
	CYCLE
};

typedef pthread_mutex_t	t_mut;

typedef struct s_mind
{
	int					whoami;
	long				*set;
	long				meals;
	t_mut				*inspec;
	suseconds_t			start;
	long				last_meal;
	t_mut				*r_fork;
	t_mut				*l_fork;
}						t_mind;

typedef struct s_context
{
	long				*set;
	suseconds_t			start;
	pthread_t			*philo;
	t_mind				*mind;
	t_mut				*fork;
	t_mut				*inspec;
	int					arr_len;
	char const			**argv;
	int					ite;
}						t_context;

/* parse */
void					atoiv(t_context *c);

/* init */
bool					init(t_context *c);
bool					init_fork(t_context *c);
bool					init_sim(t_context *c);
bool					init_monitor(t_context *c);

/* philos */
bool					grab(t_mind *m);
void					*daily(void *ref);
bool					i_am_dead(t_mind *m);

/* monitor */
void					*fate(void *ref);

/* clock */
bool					am_i_dead_wait(t_mind *m, long wait);
suseconds_t				get_time(suseconds_t start);
suseconds_t				get_start(void);
suseconds_t				get_time(suseconds_t start);

/* utils */
void					safe_free(char **ptr);
void					lock(t_mut *mut);
void					unlock(t_mut *mut);

#endif