#include <stdio.h>
#include <stdarg.h>
#include <string.h>
//#include "ft_printf.h"
int ft_puthexnbr(unsigned int n);
int ft_putheXnbr(unsigned int n);
int ft_putchar(int c);
int ft_putstr(char *ptr);
int ft_putnbr(int n);
int ft_put_u_nbr(unsigned int n);
static int ft_specifiers(const char format, va_list args)
{
    if(format == 'c')
        return (ft_putchar(va_arg(args,int)));
    else if (format == 's')
        return  (ft_putstr(va_arg(args,char *)));
    else if(format == 'd' || format == 'i')
        return (ft_putnbr(va_arg(args,int)));
    else if(format == 'u')
        return (ft_put_u_nbr(va_arg(args,unsigned int)));
    else if(format == '%')
        return (ft_putchar('%'));
    else if(format == 'x')
        return (ft_puthexnbr(va_arg(args,unsigned int)));
    else if(format == 'X')
        return (ft_putheXnbr(va_arg(args,unsigned int)));
    else 
        return -1;

}
static int ft_format(const char *format,va_list args,int count)
{
    int add;
    add = 0;
    while(*format)
    {
        if(*format == '%' && *(format + 1) != '\0')
        {
            add = ft_specifiers(*(++format), args);
            count += add;
        }

        else if( *format != '%')
        {
            if(ft_putchar(*format) == -1)
                return -1;
            count ++;

        }
        else 
           
            return -1;
        format++;
    }
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count;
    if(!format)
        return -1;
    count = 0;
    va_start(args,format);
    count = ft_format(format,args,count);
    va_end(args);
    return(count);

}

int main()
{
    int a = printf("gercek %X\n",123);
    int b =ft_printf("gercek %X",123);
    printf("\n printf return : %d\n ft_printf return %d",a,b); 
}