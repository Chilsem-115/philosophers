/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 06:37:11 by itamsama          #+#    #+#             */
/*   Updated: 2025/08/28 22:22:22 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_sim	t_sim;

typedef struct s_data
{
	int	philo_count;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	max_meals;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				left;
	int				right;
	long			last_meal_ms;
	int				meals;
	pthread_t		thread;
	pthread_mutex_t	meal_mtx;
	t_sim			*sim;
}	t_philo;

typedef struct s_sim
{
	t_data			cfg;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	state_mtx;
	int				finished;
	long			start_ms;
	pthread_t		monitor;
}	t_sim;

/* utils */
int		ft_atoi(const char *str);

/* init */
int		parse(t_sim *sim, int argc, char **argv);
int		init_philo(t_sim *sim);
void	destroy_philo(t_sim *sim);

#endif
