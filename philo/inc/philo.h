/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:33 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/14 03:27:38 by leschunc         ###   ########.fr       */
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
# define ERR 1
# define OK 0
# define SIM_SIZE 2000

# define MSG1 "%5ld%3d has taken a fork\n"
# define MSG2 "%5ld%3d is eating\n"
# define MSG3 "%5ld%3d is sleeping\n"
# define MSG4 "%5ld%3d is thinking\n"
# define MSG5 "%5ld%3d has died\n"
# define ERR1 "\033[31mCAPTCHA\033[0m: name all %ld philosophers\n"
# define ERR2 "%5ld%3d has died \033[31mbecause of YOU\033[0m\n"

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
	suseconds_t			*start;
	bool				*simulation;
	long				*set;
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
	suseconds_t			start[1];
	bool				simulation[1];
	long				*set;
	t_mut				*inspec;
	t_mut				broadcast[1];
	pthread_t			*philo;
	t_mind				*mind;
	t_mut				*fork;
	int					ite;
	char				**argv;
	int					arr_len;
}						t_context;

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
long					pos(long num);
void					msg(int num, t_mind *m, t_context *c, int i);

#endif