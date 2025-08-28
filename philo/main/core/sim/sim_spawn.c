/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_spawn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:24:39 by itamsama          #+#    #+#             */
/*   Updated: 2025/08/28 22:24:57 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	spawn_philos(t_sim *sim, int *out_created)
{
	int	i;

	*out_created = 0;
	i = 0;
	while (i < sim->cfg.philo_count)
	{
		if (pthread_create(&sim->philo[i].thread, NULL,
				philo_routine, &sim->philo[i]) != 0)
			break ;
		i++;
	}
	*out_created = i;
	return (0);
}

int	spawn_monitor(t_sim *sim)
{
	if (pthread_create(&sim->monitor, NULL, monitor_routine, sim) != 0)
	{
		stop_simulation(sim);
		return (1);
	}
	return (0);
}
