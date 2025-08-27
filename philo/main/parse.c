/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 06:35:18 by itamsama          #+#    #+#             */
/*   Updated: 2025/08/27 06:56:02 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

static int validate(t_sim *sim)
{
	if (sim->number_of_philosophers == -1)
		return (1);
	if (sim->time_to_die == -1)
		return (1);
	if (sim->time_to_eat == -1)
		return (1);
	if (sim->time_to_sleep == -1)
		return (1);
	if (sim->max_eat_count == -1)
		return (1);
	return (0);
}

static void	init_program(t_sim *sim, char **argv, int argc)
{
	sim->number_of_philosophers = ft_atoi(argv[1]);
	sim->time_to_die = ft_atoi(argv[2]);
	sim->time_to_eat= ft_atoi(argv[3]);
	sim->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		sim->max_eat_count = ft_atoi(argv[5]);
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

int	parse(t_sim *sim, int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (check_args(argc, argv))
		{
			printf("invalid input\n");
			return (0);
		}
		init_program(sim, argv, argc);
		if (validate(sim))
		{
			printf("invalid input\n");
			return (0);
		}
		else
			printf("success\n");
	}
	else
		instruction_msg();
	return (1);
}
