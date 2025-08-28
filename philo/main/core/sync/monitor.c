
#include "core.h"

static int philo_get_meals(t_philo *p)
{
    int v;
    pthread_mutex_lock(&p->meal_mtx);
    v = p->meals;
    pthread_mutex_unlock(&p->meal_mtx);
    return v;
}

static int	find_starved(t_sim *sim, long now)
{
	int		i;
	long	last;

	i = 0;
	while (i < sim->cfg.philo_count)
	{
		last = philo_get_last_meal(&sim->philo[i]);
		if (now - last > sim->cfg.t_die)
			return (i);
		i++;
	}
	return (-1);
}

/* return 1 if max_meals is set and all philos reached it, else 0 */
static int	quota_reached(t_sim *sim)
{
	int	i;
	int	need;

	need = sim->cfg.max_meals;
	if (need == 0)
		return (0);
	i = 0;
	while (i < sim->cfg.philo_count)
	{
		if (philo_get_meals(&sim->philo[i]) < need)
			return (0);
		i++;
	}
	return (1);
}

static int	monitor_step(t_sim *sim)
{
	long	now;
	int		idx;

	now = new_ms();
	idx = find_starved(sim, now);
	if (idx >= 0)
	{
		log_status(sim, sim->philo[idx].id, "died", 1);
		stop_simulation(sim);
		return (1);
	}
	if (quota_reached(sim))
	{
		stop_simulation(sim);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_sim	*sim;

	sim = (t_sim *)arg;
	while (!sim_get_finished(sim))
	{
		if (monitor_step(sim))
			break ;
		usleep(1000);
	}
	return (NULL);
}
