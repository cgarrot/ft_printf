#include <stdio.h>
#include <limits.h>


void	print_long(long long val)
{
	if (val < 0)
		printf("%lld\n", val);
}

int		main(int argc, char **argv)
{
	long long value;

	value = -8;
	print_long(-8);
	printf("%lld\n", value);
	return (0);
}
