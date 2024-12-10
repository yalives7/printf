#include <unistd.h>

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (*str)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		count++;
	}
	return (count);
}