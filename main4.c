#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	ft_printf("[%d]\n", ft_printf("%#.o | %#.0o", 0, 0));
	dprintf(1, "[%d]\n", dprintf(1, "%#.o | %#.0o", 0, 0));
	return (0);
}
