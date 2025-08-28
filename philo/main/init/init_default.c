
#include "app.h"

static void	set_default_vars(t_sim *sim)
{
	int	i;
	int	count;

	count = sim->cfg.philo_count;
	i = 0;
	while (i < count)
	{
		sim->philo[i].id = i + 1;
		sim->philo[i].left = i;
		sim->philo[i].right = (i + 1) % count;
		sim->philo[i].meals = 0;
		sim->philo[i].last_meal_ms = 0;
		sim->philo[i].sim = sim;
		i++;
	}
}

static int	init_forks(pthread_mutex_t *forks, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	set_philo(t_sim *sim)
{
	int n;

	n = sim->cfg.philo_count;
	sim->philo = (t_philo *)malloc(sizeof(t_philo) * n);
	sim->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n);
	if (!sim->philo || !sim->forks)
		return (1);
	if (pthread_mutex_init(&sim->print_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&sim->state_mtx, NULL) != 0)
		return (1);
	if (init_forks(sim->forks, n))
		return (1);
	return (0);
}

int	init_philo(t_sim *sim)
{
	if (set_philo(sim))
		return (1);
	set_default_vars(sim);
	return (0);
}
