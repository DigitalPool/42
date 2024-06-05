#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void rush( int x, int y)
{
    char array[3] = {'A', 'B', 'C'};
    char B = 'B';
    int i = 0;
    int j = 0;

    while (i < x)
    {
        j = 0;
        while (j < y)
        {
            if (j == 0 )
                ft_putchar(array[0]);
            else if (j == y - 1 )
                ft_putchar(array[2]);
			else
                ft_putchar(array[1]);
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int main()
{
    rush(4, 5);
    return 0;
}
