
#include "core.h"

void	stop_simulation(t_sim *sim)
{
	pthread_mutex_lock(&sim->state_mtx);
		sim->finished = 1;
	pthread_mutex_unlock(&sim->state_mtx);
}

int	stop_and_join(t_sim *sim, int n)
{
	stop_simulation(sim);
	join_philos(sim, n);
	return (0);
}

int	sim_get_finished(t_sim *sim)
{
	int v;

	pthread_mutex_lock(&sim->state_mtx);
	v = sim->finished;
	pthread_mutex_unlock(&sim->state_mtx);
	return (v);
}
