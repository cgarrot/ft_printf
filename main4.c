#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	/*ft_printf("[%d]\n", ft_printf("% +d\n", 42));
	printf("[%d]\n", printf("% +d\n", 42));*/
	ft_printf("[%d]\n", ft_printf("%%\n"));
	printf("[%d]\n", printf("%%\n"));
	ft_printf("[%d]\n", ft_printf("%03.5%\n"));
	printf("[%d]\n", printf("%03.5%\n"));
	ft_printf("[%d]\n", ft_printf("%-5%\n"));
	printf("[%d]\n", printf("%-5%\n"));
	ft_printf("[%d]\n", ft_printf("%.0%\n"));
	printf("[%d]\n", printf("%.0%\n"));
	ft_printf("[%d]\n", ft_printf("%%\n", "test"));
	printf("[%d]\n", printf("%%\n", "test"));
	ft_printf("[%d]\n", ft_printf("%   %\n", "test"));
	printf("[%d]\n", printf("%   %\n", "test"));
	return (0);
}
