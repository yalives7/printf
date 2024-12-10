// buaraya sevilay variadic fonksiyonun bir örneğini yapıcaz

#include <stdio.h>
#include<stdarg.h>

void sevilay(int count,...)
{
    va_list veri;
    va_start(veri,count);

    for(int i = 0; i < count ;i++)
    {
        if(i % 3 == 0 )
        {
            int yaz = va_arg(veri,int);
            printf("%d ",yaz);
        }
        else
            {
                char yaz = va_arg(veri,char);
                printf("%c ",yaz);
            }
    }
    

}

int main()
{
    sevilay(9,2,'e','v',2,'o','l',3,'d','u');
   
}