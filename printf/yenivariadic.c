#include <stdio.h>
#include <stdarg.h>

int serefsiz(int d,int a,...)
{
    va_list args;
    va_start(args,a);
    int i= 0;
    while(d  > 0)
    {
         i= va_arg(args,int);
         printf("%d\n\n",i);
        printf("%d\n",(i+a));
        i++;
        d--;
    }
    va_end(args);
}

int main()
{
    serefsiz(5,4,1,2,3,4,5);
}