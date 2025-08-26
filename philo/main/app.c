
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

static int	setup_sim(t_sim *sim, int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		init_program(sim, argv, argc);
		if (validate(sim))
		{
			printf("invalid input\n");
			return (0);
		}
		else
			printf("success");
	}
	else
		instruction_msg();
	return (1);
}

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (setup_sim(&sim, argc, argv))
		return (0);
}
