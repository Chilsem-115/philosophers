/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 06:36:48 by itamsama          #+#    #+#             */
/*   Updated: 2025/08/27 08:21:09 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

static int	init_philo(t_sim *sim)
{
	sim->philo = (t_philo *)malloc(sizeof(t_philo) * sim->philo_count);
	if (!sim->philo)
		return (1);
	return (0);
}

static void	set_default_vars(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_count)
	{
		sim->philo[i].id = i + 1;
		sim->philo[i].left = 
		sim->philo[i].meals = 0;
		sim->philo[i].last_meal_ms = 0;
		sim->philo[i].is_dead = 0;
		sim->philo[i].sim = sim;
		i++;
	}
	return ;
}

static int	set_philo(t_sim *sim)
{
	if (init_philo(sim))
		return (1);
	return (0);
	set_default_vars(sim);
}

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (parse(&sim, argc, argv))
		return (0);
	if (set_philo(&sim))
	{
		printf("Error: insufficient memory.\n");
		return (1);
	}
	return (0);
}
