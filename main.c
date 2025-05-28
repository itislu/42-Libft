#include "ft_printf.h"
#include "libft.h"
#include <assert.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/cdefs.h>
#include <unistd.h>
#include <printf.h>

void func(void);

#include <bsd/string.h>
int main(int argc, char *argv[]) 
{
	(void)argc;
	argv[1] = NULL;
	// long long ret;
	size_t og;
	size_t ft;
	(void)og;
	(void)ft;

#if FT_FIRST
    // Test ft_strlcat
    printf("\nft_strlcat:\n");
    printf("Before: %s\n", str2);
    ft = ft_strlcat(ftbuf, src, size);
    printf("After:  %s\n", str2);
    printf("Return: %zu\n", ret2);
#endif
    // Test original strlcat
    printf("\nOriginal strlcat:\n");
    printf("Before: %s\n", str1);
    og = strlcat(ogbuf, src, size);
    printf("After:  %s\n", str1);
    printf("Return: %zu\n", ret1);
#if !FT_FIRST
    // Test ft_strlcat
    printf("\nft_strlcat:\n");
    printf("Before: %s\n", str2);
    ft = ft_strlcat(ftbuf, src, size);
    printf("After:  %s\n", str2);
    printf("Return: %zu\n", ret2);
#endif

	// og = strtok(NULL, NULL);
	// printf("strtok complete\n");
	// ft = ft_strtok(NULL, NULL);
	// printf("ft_strtok complete\n");
	// printf("og: |%s|\n", og);
	// printf("ft: |%s|\n", ft);

	// og = printf(NULL);
	// ft = ft_printf(NULL);

	// og = strndup(NULL, 0);
	// ft = ft_strndup(NULL, 0);

	// printf("og: |%d|\n", og);
	// printf("ft: |%d|\n", ft);

	// free(og);

	func();
}

#include <bsd/string.h>
void func(void)
{
	printf("og: %s\n", strnstr("", "", 0));
	printf("ft: %s\n", ft_strnstr("", "", 0));
}
