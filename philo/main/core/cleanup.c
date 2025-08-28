/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:38:52 by itamsama          #+#    #+#             */
/*   Updated: 2025/08/28 22:23:05 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void	destroy_forks(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->cfg.philo_count)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
}

static void	destroy_philo_mtx(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->cfg.philo_count)
	{
		pthread_mutex_destroy(&sim->philo[i].meal_mtx);
		i++;
	}
}

void	cleanup(t_sim *sim)
{
	pthread_mutex_destroy(&sim->print_mtx);
	pthread_mutex_destroy(&sim->state_mtx);
	destroy_philo_mtx(sim);
	destroy_forks(sim);
	free(sim->philo);
	free(sim->forks);
	sim->philo = NULL;
	sim->forks = NULL;
}
