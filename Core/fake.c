#include <get_next_line.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main ()
{

	char BUFFER [BUFFER_SIZE];
	int fd;

	fd = open("academic.txt", O_RDONLY);
	if (fd == -1)
	{
		write (1, "ERROR\n",7);
		return (-1);
	}

	ssize_t bytes_read = read(fd, BUFFER, (sizeof(BUFFER)));
	if (bytes_read == -1)
	{
		write (1,"ERROR\n",7);
		return (-1);
	}

	size_t i = 0;
	char * first_book = malloc (bytes_read * sizeof(char));
	char * second_book = malloc (bytes_read * sizeof(char));

	while ((BUFFER[i]) != '\n')
	{
		first_book[i] = BUFFER[i];
		i++;
	}
	first_book[i] = '\n';
	printf("%s", first_book);

	write(1, "$\n", 2);

	while (BUFFER[i] != '\0')
	{
		second_book[i] = BUFFER[i];
		i++;
	}
	printf("%s", second_book);
	write(1, "$$\n", 3);

	return 0;
}

static char * set_line (char * line_buffer)
{
	char * left_c;
	ssize_t i = 0;

	if (!line_buffer)
		{
		return NULL;
	}

	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;

	if (line_buffer[i] == 0 || line_buffer[1] == 0)
	{
		return NULL;
	}

	left_c = ft_substr (line_buffer, i + 1, ft_strlen(line_buffer) - i);


	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}

	return left_c;
}







static char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);

		if (b_read == -1)
		{
			free(left_c);
			return (NULL);
		}

		else if (b_read == 0)

			break ;

		buffer[b_read] = 0;

		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;

		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}
