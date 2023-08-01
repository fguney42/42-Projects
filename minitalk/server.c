#include "minitalk.h"

int ft_int(int i)
{
    int value = 0;
    int val = 1;
    if (i == 0)
    return (1);
    while (value < i)
    {
        val *= 2;
        value++;
    }
    return (val);
}
void ft_signal(int sig)
{
    static int i = 0;
    static char c = 0;
    int value = 0;
    if (i == 8)
    {
        printf("%c", c); // ft_printf(); ?
        fflush(stdout);
        i = 0;
        c = 0;
    }
    if (sig == SIGUSR2)
    {
       c += ft_int(i);
    }
    i++;
}
int main(int argc,char **argv)
{
    int value = getpid();
    printf("PID: %d\n", value);
    while (1)
    {
    signal(SIGUSR1, ft_signal);
    signal(SIGUSR2, ft_signal);
    pause();
    }
    return (0);
}