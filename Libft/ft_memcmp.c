#include "libft.h"

int	ft_memcmp(const void *dst, const void *str, size_t n)
{
	size_t	i;
	int	diff;
	unsigned char	*str2;
	unsigned char	*dst2;

	dst2 = (unsigned char*)dst;
	str2 = (unsigned char *)str;
	i = 0;
	diff = 0;
	if (n)
		while (n--)
			if (*dst2++ != *str2++)
				return (*(--dst2) - *(--str2));
	return (0);
}
