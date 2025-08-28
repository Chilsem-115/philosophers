/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@studen.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:23:40 by itamsama          #+#    #+#             */
/*   Updated: 2025/08/28 22:23:54 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "app.h"

/* core */
int		simulate(t_sim *sim);
long	new_ms(void);
int		log_status(t_sim *sim, int id, const char *msg, int is_death);
void	cleanup(t_sim *sim);

/* spawn / join */
int		spawn_philos(t_sim *sim, int *out_created);
int		spawn_monitor(t_sim *sim);
int		join_monitor(t_sim *sim);
int		join_philos(t_sim *sim, int count);

/* state */
void	stop_simulation(t_sim *sim);
int		stop_and_join(t_sim *sim, int n);
int		sim_get_finished(t_sim *sim);

/* routines in sync */
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);
void	forks_take(t_philo *p);
void	forks_put(t_philo *p);

/* action */
int		log_status(t_sim *sim, int id, const char *msg, int is_death);
void	philo_set_meal(t_philo *p, long ms_now);
long	philo_get_last_meal(t_philo *p);

#endif
