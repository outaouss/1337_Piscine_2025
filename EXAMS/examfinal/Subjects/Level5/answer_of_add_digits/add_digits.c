#include <unistd.h>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}
void    ft_putnbr(int nb)
{
    if (nb < 0)
   {
    ft_putchar('-');
    nb = -nb;
   }
   if (nb >= 10)
   {
    ft_putnbr(nb / 10);
}
ft_putchar(nb % 10 +'0');
}

int ft_atoi(char c)
{
    return (c - '0');
}
int main(int argc, char **argv)
{
    int i = 0;
    int result = 0;
    int count = 0;
    int p = 0;
    while (argv[1][i] != '\0')
    {
        count = ft_atoi(argv[1][i]);
        if (argv[1][i + 1])
        {
            result = result + count + ft_atoi(argv[1][i + 1]);
            i++;
        }
        i++;
    }
    int sum;
    while (result >= 10)
    {
        sum = 0;

        while (result > 0)
        {
            sum += result % 10;
            result /= 10;
        }
        result = sum;
    }
    ft_putnbr(sum);
}
