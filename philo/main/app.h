
#ifndef PHILO_H
#define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define MAX_PHILO 200

typedef struct s_philo
{
	int			id;
	pthread_mutex_t	left;
	pthread_mutex_t	right;
	long		last_meal_ms;
	int			meals;
	pthread_t	thread;
}	t_philo;

typedef struct s_sim
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_eat_count;
}	t_sim;

/* utils */
int	ft_atoi(const char *str);

#endif
