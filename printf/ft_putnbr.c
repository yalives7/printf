
#include <unistd.h>
#include <stdio.h>
int ft_putchar(int c);
int ft_putnbr(int n)
{
    int count = 0;
    if(n == -2147483648)
       {if(write(1,"-2147483648",11)== -1)
       return -1;
        return(11);}
    else if( n < 0)
    {
        count++;
        ft_putchar('-');
        n *= -1;
    }
    
    if(n >= 10)
    {
        count +=ft_putnbr(n/10);
        ft_putnbr(n%10);
    }
    if ( n <= 9 && n >= 0)
    {
       if(ft_putchar(n + '0') == -1)
        return -1;
    }
    count++;
    return count;
}