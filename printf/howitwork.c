#include <stdio.h>
#include <unistd.h>

int main()
{
 int x = 12;
 int *ptr =&x;
  uintptr_t  a = (uintptr_t )ptr;
  printf("%p",a);
  printf("%p",);

}