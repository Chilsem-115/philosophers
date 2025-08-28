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
#include "core.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (parse(&sim, argc, argv))
		return (1);
	if (init_philo(&sim))
	{
		printf("Error: insufficient memory.\n");
		return (1);
	}
	if (simulate(&sim))
		return (1);
	return (0);
}
