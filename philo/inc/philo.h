/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:33 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/17 18:30:34 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define ODD 1
# define EVEN 0
# define ERR 1
# define OK 0
# define SIM_MAX 2442

# define MSG1 "\033[34m%5ld %3d has taken a fork\n\033[0m"
# define MSG2 "\033[36m%5ld %3d has taken a fork\n\033[0m"
# define MSG3 "\033[32m%5ld %3d is eating\n\033[0m"
# define MSG4 "\033[35m%5ld %3d is sleeping\n\033[0m"
# define MSG5 "\033[33m%5ld %3d is thinking\n\033[0m"
# define MSG6 "\033[31m%5ld %3d has died\n\033[0m"

# define E_MANY "\033[31mCAPTCHA: name all %d philosophers\n\033[0m"
# define E_MURD "\033[31m%5ld %3d has died, you starved her to death\n\033[0m"
# define E_RANGE "Range: 1 - 2147483647\n"
# define E_INT "Digit-only non-zero INTs allowed\n"

enum					e_print
{
	HASFORK,
	HASFORKS,
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
	suseconds_t			*start;
	bool				*simulation;
	int					*set;
	t_mut				*inspec;
	t_mut				*broadcast;
	int					whoami;
	long				meals;
	long				last_meal;
	t_mut				*r_fork;
	t_mut				*l_fork;
}						t_mind;

typedef struct s_context
{
	suseconds_t			start;
	bool				simulation;
	int					*set;
	t_mut				*inspec;
	t_mut				broadcast;
	pthread_t			*philo;
	t_mind				*mind;
	t_mut				*fork;
	int					ite;
	char				**argv;
	int					arr_len;
}						t_context;

bool					one_lonely_philo(t_context *c);
void					give_free_will(t_context *c);
void					*fate(void *ref);
void					*daily(void *ref);

bool					atoiv(t_context *c);
int						ft_isdigit(char c);
void					*slow_death(void *ref);
int						atonum(const char *nptr);
suseconds_t				get_start(void);
suseconds_t				get_time(suseconds_t start);

void					lock(t_mut *mut);
void					unlock(t_mut *mut);
bool					killed(t_mind *m);
bool					am_i_dead_wait(t_mind *m, long wait);
long					mod(long num);
void					msg(int num, t_mind *m, t_context *c, int i);

void					join_abort(t_context *c, int limit);
void					join_exit(t_context *c);

#endif