/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 06:35:18 by itamsama          #+#    #+#             */
/*   Updated: 2025/08/27 08:03:49 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

/* only numbers allowed */
static int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int validate(const t_sim *sim)
{
	const t_data	*c;

	c = &sim->cfg;
	if (c->philo_count == -1)
		return (1);
	if (c->t_die == -1)
		return (1);
	if (c->t_eat == -1)
		return (1);
	if (c->t_sleep == -1)
		return (1);
	if (c->max_meals == -1)
		return (1);
	return (0);
}

static void	set_cfg(t_sim *sim, char **argv, int argc)
{
	sim->cfg.philo_count = ft_atoi(argv[1]);
	sim->cfg.t_die = ft_atoi(argv[2]);
	sim->cfg.t_eat = ft_atoi(argv[3]);
	sim->cfg.t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		sim->cfg.max_meals = ft_atoi(argv[5]);
}

static void	instruction_msg(void)
{
	printf("Usage:\n");
	printf("  ./philo <number_of_philosophers>\n");
	printf("         <time_to_die>\n");
	printf("         <time_to_eat>\n");
	printf("         <time_to_sleep>\n");
	printf("         [number_of_times_each_philosopher_must_eat]\n");
	printf("\nRequires 4 or 5 arguments.\n");
}

/*
 * notice:
 * 		- ft_atoi returns -1 in case of overflow
 *		- parse returns 0 on success, 1 on error
 * */
int	parse(t_sim *sim, int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (check_args(argc, argv))
		{
			printf("invalid input\n");
			return (1);
		}
		set_cfg(sim, argv, argc);
		if (validate(sim))
		{
			printf("invalid input\n");
			return (1);
		}
		return (0);
	}
	else
		instruction_msg();
	return (1);
}
