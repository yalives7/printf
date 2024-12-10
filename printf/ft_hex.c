#include <stdio.h>

int ft_putchar(int n);

int ft_putheXnbr(unsigned long long n)
{
    int count =0;
    if(n >= 16)
    {
      count += ft_putheXnbr(n/16);
       ft_putheXnbr(n %16);
    }
    else if(n >=10 && n<= 15)
    {
        char str[7]="ABCDEF";
        if(ft_putchar(str[n%10]) ==-1)
        return -1;
    }
    else if(n >= 0 && n <= 9)
        {
            if(ft_putchar(n + '0') == -1)
            return -1;
        }
    count++;
    return count;
}
int ft_puthexnbr(unsigned long long n)
{
    int count =0;
    if(n >= 16)
    {
      count += ft_puthexnbr(n/16);
       ft_puthexnbr(n %16);
    }
    else if(n >=10 && n<= 15)
    {
        char str[7]="abcdef";
        if(ft_putchar(str[n%10])==-1)
            return -1;
    }
    else if(n >= 0 && n <= 9)
    { 
        if(ft_putchar(n + '0')==-1)
            return -1;
    }
    count++;
    return count;
}


/*int main()
{
   int a = ft_putheXnbr(123);
   int b = printf("%X",123);
   printf("\nbu sahte %d,bu gercek %d",a,b);
}*/
