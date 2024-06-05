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
