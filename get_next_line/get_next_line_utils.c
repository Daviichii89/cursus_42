#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (*s == (char)c)
        return ((char *)s);
    else
        return (0);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    int i;
    int j;
    int len;

    if (!s1 || !s2)
        return (0);
    i = ft_strlen(s1);
    j = ft_strlen(s2);
    len = i + j + 1;
    str = (char *)malloc(len * sizeof(char));
    if (!str)
        return (0);
    ft_strlcpy(str, (char *)s1, i + 1);
    ft_strlcat(&str[i], (char *)s2, j + 1);
    return (str);
}
