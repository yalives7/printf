#include <unistd.h>
int ft_putchar(int c);
int ft_putstr(char *ptr)
{
    int count = 0;
    int i = 0;
    if(!ptr)
    {
        if(write(1,"(null)",6) == -1)
            return (-1);
        return (6);

    }
        
    while(*ptr)
    {
       if( ft_putchar(*ptr) == -1);
        return -1;
        count ++;
        ptr++;
    }
     return (count);
}
