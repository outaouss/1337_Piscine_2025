#include <unistd.h>
#include <stdio.h>


int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

void ft_putstr(char *str)
{
    int i = 0;
    int space = 0;
    int last = ft_strlen(str) - 1;

    while (str[i] == ' ')
        i++;
    
    int start = i;

    while (last >= 0 && str[last] == ' ')
        last--;
    
    int end = last;
    while(str[start] && start <= last)
    {
        if (str[start] == ' ')
        {
            while(str[start] == ' ')
                start++;
            write(1, " ", 1);
        }
        if (str[start])
        {
            write(1, &str[start], 1);
            start++;
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ft_putstr(av[1]);
    }
    write(1, "\n", 1);
    return (0);
}