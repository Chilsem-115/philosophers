
#include "core.h"

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (!sim_get_finished(p->sim))
		usleep(1000);
	return (NULL);
}
