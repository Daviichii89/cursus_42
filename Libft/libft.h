#ifndef _LIBRERIA
# define _LIBRERIA
# include <stddef.h>

int				ft_atoi(const char *str);
void    		ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t nitems, size_t size);
int				ft_isalnum(int c);
int 			ft_isalpha(int c);
int 			ft_isascii(int c);
int 			ft_isdigit(int c);
int 			ft_isprint(int c);
void    		*ft_memchr(const void *str, int c, size_t n);
int 			ft_memcmp(const void *p1, const void *p2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void 			*ft_memmove(void *dest, const void *src, size_t n);
void    		*ft_memset(void *s, int c, size_t n);
char    		*ft_strchr(const char *s, int c);
char    		*ft_strdup(const char *src);
size_t			ft_strlcat(char *dest, char *src, size_t size);
size_t			ft_strlcpy(char *dest, char *src, size_t size);
size_t          ft_strlen(const char *str);
int 			ft_strncmp(char *s1, char *s2, size_t n);
char    		*ft_strnstr(char *str, char *to_find, size_t max_length);
char    		*ft_strrchr(const char *s, int c);
int 			ft_tolower(int c);
int 			ft_toupper(int c);

#endif
