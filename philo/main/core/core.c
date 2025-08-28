/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:23:17 by itamsama          #+#    #+#             */
/*   Updated: 2025/08/28 22:23:33 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

long	new_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

static void	seed_start_state(t_sim *sim)
{
	int	i;

	sim->finished = 0;
	sim->start_ms = new_ms();
	i = 0;
	while (i < sim->cfg.philo_count)
	{
		sim->philo[i].last_meal_ms = sim->start_ms;
		i++;
	}
}

int	simulate(t_sim *sim)
{
	int	created;

	created = 0;
	seed_start_state(sim);
	if (spawn_philos(sim, &created))
		return (stop_and_join(sim, created), 1);
	if (spawn_monitor(sim))
		return (stop_and_join(sim, created), 1);
	if (join_monitor(sim))
		return (stop_and_join(sim, sim->cfg.philo_count), 1);
	join_philos(sim, sim->cfg.philo_count);
	cleanup(sim);
	return (0);
}
