#include "../../inc/philosophers.h"

long	get_elapsed_time_microseconds(struct timeval start,
						struct timeval end)
{
	return ((end.tv_sec - start.tv_sec) * 1000000L
		+ (end.tv_usec - start.tv_usec));
}

void	ft_usleep(long usec)
{
	struct timeval	start;
	struct timeval	current;
	long			elapsed;
	long			rem;

	gettimeofday(&start, NULL);
	gettimeofday(&current, NULL);
	elapsed = get_elapsed_time_microseconds(start, current);
	rem = usec - elapsed;
	if (rem > 1000)
		usleep(rem / 2);
	while (elapsed < usec)
	{
		gettimeofday(&current, NULL);
		elapsed = get_elapsed_time_microseconds(start, current);
		rem = usec - elapsed;
		if (rem > 1000)
			usleep(rem / 2);
	}
}