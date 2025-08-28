
#include "core.h"

static void	sleep_ms(t_philo *p, long ms)
{
	long end;

	end = new_ms() + ms;
	while (!sim_get_finished(p->sim) && new_ms() < end)
		usleep(1000);
}

static void	philo_eat(t_philo *p)
{
	forks_take(p);
	if (p->sim->cfg.philo_count == 1)
	{
		sleep_ms(p, p->sim->cfg.t_die);
		forks_put(p);
		return ;
	}
	log_status(p->sim, p->id, "is eating", 0);
	philo_set_meal(p, new_ms());
	sleep_ms(p, p->sim->cfg.t_eat);
	forks_put(p);
}

static void	philo_sleep_think(t_philo *p)
{
	log_status(p->sim, p->id, "is sleeping", 0);
	sleep_ms(p, p->sim->cfg.t_sleep);
	log_status(p->sim, p->id, "is thinking", 0);
	usleep(500);
}

/* id & 1 = 0 when even and 1 when odd*/
void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if ((p->id & 1))
		usleep(100);
	while (!sim_get_finished(p->sim))
	{
		if (p->id & 1)
			usleep(500);
		philo_eat(p);
		if (sim_get_finished(p->sim))
			break ;
		philo_sleep_think(p);
	}
	return (NULL);
}
