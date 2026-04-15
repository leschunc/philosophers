/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:33 by leschunc          #+#    #+#             */
/*   Updated: 2026/04/15 16:38:37 by leschunc         ###   ########.fr       */
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

# define NOCOLOR "\033[0m"
# define CYAN "\033[36m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define BLUE "\033[34m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define FORMAT "%5ld %3d "

# define MSG1 BLUE FORMAT "has taken a fork\n" NOCOLOR
# define MSG2 CYAN FORMAT "has taken a fork\n" NOCOLOR
# define MSG3 GREEN FORMAT "is eating\n" NOCOLOR
# define MSG4 MAGENTA FORMAT "is sleeping\n" NOCOLOR
# define MSG5 YELLOW FORMAT "is thinking\n" NOCOLOR
# define MSG6 RED FORMAT "has died\n" NOCOLOR
# define ERR1 RED "CAPTCHA: name all %ld philosophers\n" NOCOLOR
# define ERR2 RED FORMAT "has died, you starved her to death by giving her one fork\n" NOCOLOR

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