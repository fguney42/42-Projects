#include "minitalk.h"

int ft_strlen(char *str)
{
   int i = -1;
   while (str[++i])
   ;
   return (i);
}

int ft_atoi(char *str)
{
   int value = 0;
   int i = 0;
   while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
   {
      value *= 10;
      value += str[i] - '0';
      i++;
   }
   return (value);
}
void ft_send(int *value, int pid)
{
   int i = 0;
   while (i < 8)
   {
      if (value[i] == 0)
      {kill(pid, SIGUSR1);}
      else if (value[i] == 1)
      {kill(pid, SIGUSR2);}
      usleep(1000);
      i++;
   }
}
int *ft_byte(char value, pid_t pid, int **ptr)
{
   int v = 0;
   int a = 0;
   while (v < 8)
   {
      ptr[0][a++] = (value % 2);
      value = value >> 1;
      v++;
   }
   return ptr[0];
}
int *ft_swap(char **str, char *argv, pid_t pid)
{
   int i = 0;
   int a = 0;
   int *value = malloc(sizeof(int) * 8);
   while (strlen(argv) + 1 > i)
   {
      str[a][i] = argv[i];
      ft_byte(str[a][i], pid, &value);
      ft_send(value, pid);
      i++;
   }
   str[a][i] = 0;
   return (value);
}
int main(int argc,char **argv)
{
   pid_t id = 0;
   int *value;
   char *str = (char *)malloc(sizeof(char) * ft_strlen(argv[2]));
   if (argc == 3)
   {
      id = ft_atoi(argv[1]);
      value = ft_swap(&str, argv[2], id);
   }
   free(str);
   return (0);
}