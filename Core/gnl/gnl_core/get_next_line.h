/*
 * The MAX_FD macro is defined based on the max number of file descriptors
 * based on my current OS and what I found online (MacOS Ventura 13.0)
 * (this information is particularly hard to find, or I just don't know
 * what to search for on Google)
 */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# define MAX_FD 10240
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);

static char	*move_behind_line (char *line_buffer);
size_t		ft_strlen(const char *s);
char		*ft_substr(char *s, unsigned int start, size_t len);
int			ft_strchr(const char *s, int c);
char		*fill_the_line (int fd, char *left_line, char *buffer);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
// void	fill_str(char *res, char *s1, char *s2);

#endif
