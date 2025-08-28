/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:25:49 by itamsama          #+#    #+#             */
/*   Updated: 2025/08/28 22:26:41 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	log_status(t_sim *sim, int id, const char *msg, int is_death)
{
	int	should_print;

	pthread_mutex_lock(&sim->state_mtx);
	should_print = ((!sim->finished) || is_death);
	pthread_mutex_unlock(&sim->state_mtx);
	pthread_mutex_lock(&sim->print_mtx);
	if (should_print)
		printf("%ld %d %s\n", new_ms() - sim->start_ms, id, msg);
	pthread_mutex_unlock(&sim->print_mtx);
	return (should_print);
}

void	philo_set_meal(t_philo *p, long ms_now)
{
	pthread_mutex_lock(&p->meal_mtx);
	p->last_meal_ms = ms_now;
	p->meals++;
	pthread_mutex_unlock(&p->meal_mtx);
}

long	philo_get_last_meal(t_philo *p)
{
	long	v;

	pthread_mutex_lock(&p->meal_mtx);
	v = p->last_meal_ms;
	pthread_mutex_unlock(&p->meal_mtx);
	return (v);
}
