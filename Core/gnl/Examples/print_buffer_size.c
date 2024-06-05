
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main ()
{
	size_t BUFFER_SIZE = 10000;

	char BUFFER [BUFFER_SIZE];
	int fd;

	fd = open("academic.txt", O_RDONLY);
	if (fd < 0)
	{
		write (1, "ERROR\n",7);
		return (-1);
	}

	ssize_t bytes_read = read(fd, BUFFER, sizeof(BUFFER) - 1);
	if (bytes_read < 0)
	{
		write (1,"ERROR\n",7);
		return (-1);
	}

	printf("%zd\n", (bytes_read));
	close(fd);

	return 0;
}






#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_isnewline (char c)
{
	return (c == '\n');
}

int main ()
{
	size_t BUFFER_SIZE = 10000;

	char BUFFER [BUFFER_SIZE];
	int fd;

	fd = open("academic.txt", O_RDONLY);
	if (fd < 0)
	{
		write (1, "ERROR\n",7);
		return (-1);
	}

	ssize_t bytes_read = read(fd, BUFFER, sizeof(BUFFER) - 1);
	if (bytes_read < 0)
	{
		write (1,"ERROR\n",7);
		return (-1);
	}

	size_t i = 0;
	char * first_book = malloc (bytes_read * sizeof(char));
	char * second_book = malloc (bytes_read * sizeof(char));

	while ((BUFFER[i]) != '\n')
	{
		first_book[i] = write(1, &BUFFER[i], 1);
		i++;
	}
	first_book[i] = write(1, "$", 1);
	// printf ("%s", first_book);

	while (BUFFER[i] != '\0')
	{
		second_book[i] = write(1, &BUFFER[i], 1);
		i++;
	}
	write(1, "\n", 1);

	return 0;
}
