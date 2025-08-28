
#include "core.h"

void	forks_take(t_philo *p)
{
	int	a;
	int	b;
	int	t;

	a = p->left;
	b = p->right;
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	pthread_mutex_lock(&p->sim->forks[a]);
	log_status(p->sim, p->id, "has taken a fork", 0);
	if (p->sim->cfg.philo_count == 1)
		return ;
	pthread_mutex_lock(&p->sim->forks[b]);
	log_status(p->sim, p->id, "has taken a fork", 0);
}

void	forks_put(t_philo *p)
{
	if (p->left == p->right)
	{
		pthread_mutex_unlock(&p->sim->forks[p->left]);
		return ;
	}
	pthread_mutex_unlock(&p->sim->forks[p->left]);
	pthread_mutex_unlock(&p->sim->forks[p->right]);
}
