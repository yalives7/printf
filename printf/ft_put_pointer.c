#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int ft_putchar(int n);
int ft_putheXnbr(unsigned int n);
int ft_putptr(void *ptr)
{
    int count = 0;
    if(ptr == NULL)
        return -1;
    uintptr_t adress = (uintptr_t)ptr;
   if(write(1,"0x",2) == -1)
       {
            return -1;
       }
       count += 2;
    count += ft_putheXnbr((unsigned long long )(adress));
    return count;
}
int main()
{
    char c = 'd';
    ft_putptr(&c);
    printf("\n%p",&c);
}