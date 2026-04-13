/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:33 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/14 00:09:28 by leschunc         ###   ########.fr       */
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
	suseconds_t			*start;
	long				last_meal;
	t_mut				*r_fork;
	t_mut				*l_fork;
	t_mut				*broadcast;
}						t_mind;

typedef struct s_context
{
	long				*set;
	bool				simulation[1];
	suseconds_t			start[1];
	pthread_t			*philo;
	t_mind				*mind;
	t_mut				*fork;
	t_mut				*inspec;
	t_mut				broadcast[1];
	int					arr_len;
	char				**argv;
	int					ite;
}						t_context;

void					lock(t_mut *mut);
void					unlock(t_mut *mut);
void					*fate(void *ref);
void					*daily(void *ref);
bool					atoiv(t_context *c);
void					give_free_will(t_context *c);
int						ft_isdigit(char c);
int						atonum(const char *nptr);
suseconds_t				get_time(suseconds_t start);
suseconds_t				get_start(void);
bool					am_i_dead_wait(t_mind *m, long wait);
bool					killed(t_mind *m);
long					pos(long num);

void					msg(int num, t_mind *m, t_context *c, int i);

#endif