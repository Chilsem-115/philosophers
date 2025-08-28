
#include "app.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num * sign > INT_MAX || num * sign <= INT_MIN)
			return (-1);
		str++;
	}
	if (num * sign <= 0)
		return (-1);
	return (num * sign);
}
