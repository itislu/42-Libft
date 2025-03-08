#include "ft_printf.h"
#include <assert.h>
#include <stdio.h>

int main(void) 
{
	int og;
	int ft;

	printf("printf:    %d\n", og = printf("%#.0o", 0));
	printf("ft_printf: %d\n", ft = ft_printf("%#.0o", 0));

	assert(og == ft);
}
