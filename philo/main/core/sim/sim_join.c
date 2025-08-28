/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:24:17 by itamsama          #+#    #+#             */
/*   Updated: 2025/08/28 22:24:31 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
