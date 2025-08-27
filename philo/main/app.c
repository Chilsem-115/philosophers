/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 06:36:48 by itamsama          #+#    #+#             */
/*   Updated: 2025/08/27 08:00:23 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

static void	set_philo(t_sim *sim)
{
}

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (parse(&sim, argc, argv))
		return (0);
	set_philo(&sim);
}
