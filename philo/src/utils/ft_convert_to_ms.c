#include "../../inc/philosophers.h"

long    ft_convert_to_ms(struct timeval start)
{
    struct timeval  end;
    long            sec;
    long            usec;
    long            ms;

    gettimeofday(&end, NULL);
    sec = end.tv_sec - start.tv_sec;
    usec = end.tv_usec - start.tv_usec;
    ms = (sec * 1000L) + (usec / 1000L);
    return (ms);
}