#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
int ft_putchar(int c);
static int	ft_puthex_lower(uintptr_t nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_puthex_lower(nbr / 16);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar("0123456789abcdef"[nbr % 16]) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putpointer(void *p)
{
	uintptr_t	ptr;
	int				count;

	ptr = (uintptr_t)p;
	count = 0;
	if (p == NULL)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	count += write(1, "0x", 2);
	if (count == -1)
		return (-1);
	count += ft_puthex_lower(ptr);
	if (count == -1)
		return (-1);
	return (count);
}
int main()
{
    char c = 'd';
    ft_putpointer(&c);
    printf("\n%p",&c);
}