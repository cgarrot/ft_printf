#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	/*ft_printf("[%d]\n", ft_printf("%%\n"));
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
printf("\n");
	
	ft_printf("[%d]\n", ft_printf("{%  P"));
	printf("[%d]\n", printf("{%  P"));
	ft_printf("[%d]\n", ft_printf("% lLhqwerty"));
	printf("[%d]\n", printf("% lLhqwerty"));
	ft_printf("[%d]\n", ft_printf("% 45Zoooooo"));
	printf("[%d]\n", printf("% 45Zoooooo"));
	
	printf("\n[%d]\n", printf("%0-66Ykkkk"));
	printf("\n[%d]\n", printf("%0-66ckkkk", 'Z'));
	printf("\n");
	*/

	/*ft_printf("[%d]\n", ft_printf("%hhu, %hhu", 0, UCHAR_MAX + 42));
	printf("[%d]\n", printf("%hhu, %hhu", 0, UCHAR_MAX + 42));*/
	/*ft_printf("[%d]\n", ft_printf("%#o", 42));
	printf("[%d]\n", printf("%#o", 42));
	ft_printf("[%d]\n", ft_printf("%#o", 0));
	printf("[%d]\n", printf("%#o", 0));
	ft_printf("[%d]\n", ft_printf("%#.o, %#.0o", 0, 0));
	printf("[%d]\n", printf("%#.o, %#.0o", 0, 0));*/
	/*ft_printf("[%d]\n", ft_printf("{%-5d}", 0));
	printf("[%d]\n", printf("{%-5d}", 0));
	ft_printf("[%d]\n", ft_printf("{% 03d}", 0));
	printf("[%d]\n", printf("{% 03d}", 0));
	ft_printf("[%d]\n", ft_printf("%03.2d", -1));
	printf("[%d]\n", printf("%03.2d", -1));
	ft_printf("[%d]\n", ft_printf("%03.2d", 1));
	printf("[%d]\n", printf("%03.2d", 1));
	ft_printf("[%d]\n", ft_printf("%.10d", -42));
	printf("[%d]\n", printf("%.10d", -42));
	ft_printf("[%d]\n", ft_printf("%.4d", 42));
	printf("[%d]\n", printf("%.4d", 42));
	ft_printf("[%d]\n", ft_printf("%.2d", 4242));
	printf("[%d]\n", printf("%.2d", 4242));
	ft_printf("[%d]\n", ft_printf("%.6d", -150));
	printf("[%d]\n", printf("%.6d", -150));
	ft_printf("[%d]\n", ft_printf("%15.4d", 424242));
	printf("[%d]\n", printf("%15.4d", 424242));
	ft_printf("[%d]\n", ft_printf("{%+03d}", 0));
	printf("[%d]\n", printf("{%+03d}", 0));*/
	ft_printf("[%d]\n", ft_printf("%4.15d", -42));
	printf("[%d]\n", printf("%4.15d", -42));
	return (0);
}
