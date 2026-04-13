#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EMPTY '\0'
# define ERR 1
# define OK 0
# define SIM_SIZE 2000

# define MSG1 "%5ld\t%3d\thas taken a fork\n"
# define MSG2 "%5ld\t%3d\tis eating\n"
# define MSG3 "%5ld\t%3d\tis sleeping\n"
# define MSG4 "%5ld\t%3d\tis thinking\n"
# define MSG5 "%5ld\t%3d\thas died\n"
# define ERR1 "\033[31mCAPTCHA\033[0m: name all %ld philosophers\n"
# define ERR2 "%5ld 0 has died \033[31mbecause of YOU\033[0m\n"

enum					e_print
{
	HASFORK,
	EATS,
	SLEEPS,
	THINKS,
	DIED,
	TOOMANY,
	YOUKILLED,
};

enum					e_attr
{
	NUM,
	DIE,
	EAT,
	SLP,
	CYC,
};

typedef pthread_mutex_t	t_mut;

typedef struct s_mind
{
	int					whoami;
	bool				*simulation;
	long				*set;
	long				meals;
	t_mut				*inspec;
	suseconds_t			start;
	long				last_meal;
	t_mut				*r_fork;
	t_mut				*l_fork;
	t_mut				*broadcast;
}						t_mind;

typedef struct s_context
{
	long				*set;
	bool				simulation[1];
	suseconds_t			start;
	pthread_t			*philo;
	t_mind				*mind;
	t_mut				*fork;
	t_mut				*inspec;
	t_mut				broadcast[1];
	int					arr_len;
	char const			**argv;
	int					ite;
}						t_context;

bool					atoiv(t_context *c);
int						ft_atoi(const char *nptr);

bool					init(t_context *c);
bool					init_fork(t_context *c);
bool					init_sim(t_context *c);
void					destroy_mutx(t_context *c);

bool					grab(t_mind *m);
void					*daily(void *ref);
bool					killed(t_mind *m);

void					*fate(void *ref);

bool					am_i_dead_wait(t_mind *m, long wait);
suseconds_t				get_time(suseconds_t start);
suseconds_t				get_start(void);
suseconds_t				get_time(suseconds_t start);

void					safe_free(char **ptr);
void					lock(t_mut *mut);
void					unlock(t_mut *mut);
void					msg(int num, t_mind *m, t_context *c, int i);

#endif