
#include "core.h"

int	join_monitor(t_sim *sim)
{
	if (pthread_join(sim->monitor, NULL) != 0)
		return (1);
	return (0);
}

int	join_philos(t_sim *sim, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_join(sim->philo[i].thread, NULL);
		i++;
	}
	return (0);
}
