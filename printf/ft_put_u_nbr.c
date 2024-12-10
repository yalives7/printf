
#include <stdio.h>
int ft_putchar(int n);
int ft_put_u_nbr(unsigned int n)
{
    unsigned int count = 0;
    printf("\n%d\n",n);
    if(n >= 10)
    {
        count += ft_put_u_nbr(n / 10);
        ft_put_u_nbr(n % 10);
    }
    if(n <= 9 && n >=0)
    {
        if(ft_putchar(n + '0') == -1);
            return -1;
    }
    count ++;
    return count;
}