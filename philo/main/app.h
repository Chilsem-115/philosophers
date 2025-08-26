
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
	int			left;
	int			right;
	long		last_mean_ms;
	int			meanls;
	pthread_t	thread;
	t_sim		*sim;
}	t_philo;

typedef struct s_sim
{
}	t_sim;


#endif
