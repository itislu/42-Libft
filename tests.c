#include "libft.h"
#include "ft_printf.h"
#include <stdint.h>
#include <stddef.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int main(void)
{
	// {
	// 	errno = 0;
	// 	printf("\nft_printf: %d\n", ft_printf("123%"));
	// 	printf("errno: %d - %s\n", errno, strerror(errno));
	// }
	// printf("\n");
	// {
	// 	errno = 0;
	// 	printf("\nprintf: %d\n", printf("123%"));
	// 	printf("errno: %d - %s\n", errno, strerror(errno));
	// }
	printf("\n-----------------------------------------------------------\n\n");
	{
		char str[10] = "123456789";
		errno = 0;
		printf("ft_snprintf: %d\n", ft_snprintf(str, 10, "123%"));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char str[10] = "123456789";
		errno = 0;
		printf("snprintf: %d\n", snprintf(str, 10, "123%"));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	// printf("\n-----------------------------------------------------------\n\n");
	// {
	// 	errno = 0;
	// 	printf("\nft_printf: %d\n", ft_printf(NULL));
	// 	printf("errno: %d - %s\n", errno, strerror(errno));
	// }
	// printf("\n");
	// {
	// 	errno = 0;
	// 	printf("\nprintf: %d\n", printf(NULL));
	// 	printf("errno: %d - %s\n", errno, strerror(errno));
	// }
	printf("\n-----------------------------------------------------------\n\n");
	{
		char str[10] = "123456789";
		errno = 0;
		printf("ft_snprintf: %d\n", ft_snprintf(str, 10, NULL));
		printf("str: |%s|\n", str);
		printf("str + 1: |%s|\n", str + 1);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char str[10] = "123456789";
		errno = 0;
		printf("snprintf: %d\n", snprintf(str, 10, NULL));
		printf("str: |%s|\n", str);
		printf("str + 1: |%s|\n", str + 1);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	// printf("\n-----------------------------------------------------------\n\n");
	// {
	// 	errno = 0;
	// 	printf("\nft_dprintf: %d\n", ft_dprintf(100, "NULL"));
	// 	printf("errno: %d - %s\n", errno, strerror(errno));
	// }
	// printf("\n");
	// {
	// 	errno = 0;
	// 	printf("\ndprintf: %d\n", dprintf(100, "NULL"));
	// 	printf("errno: %d - %s\n", errno, strerror(errno));
	// }
	printf("\n-----------------------------------------------------------\n\n");
	{
		char str[10] = "123456789";
		errno = 0;
		printf("ft_snprintf: %d\n", ft_snprintf(str, 10, "123%s", "abcdefghijklmnopqrstuvwxyz"));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char str[10] = "123456789";
		errno = 0;
		printf("snprintf: %d\n", snprintf(str, 10, "123%s", "abcdefghijklmnopqrstuvwxyz"));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	// printf("\n-----------------------------------------------------------\n\n");
	// {
	// 	char str[10] = "123456789";
	// 	errno = 0;
	// 	printf("ft_strlcpy: %zu\n", ft_strlcpy(str, "abcdefghijklmnopqrstuvwxyz", 4));
	// 	printf("str: |%s|\n", str);
	// 	printf("errno: %d - %s\n", errno, strerror(errno));
	// }
	// printf("\n");
	// {
	// 	char str[10] = "123456789";
	// 	errno = 0;
	// 	printf("strlcpy: %zu\n", strlcpy(str, "abcdefghijklmnopqrstuvwxyz", 4));
	// 	printf("str: |%s|\n", str);
	// 	printf("errno: %d - %s\n", errno, strerror(errno));
	// }
	printf("\n-----------------------------------------------------------\n\n");
	{
		char src[10] = "123456789";
		char *dst = src + 3;
		errno = 0;
		printf("ft_strlcpy: %zu\n", ft_strlcpy(dst, src, 6));
		printf("src: |%s|\n", src);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char src[10] = "123456789";
		char *dst = src + 3;
		errno = 0;
		printf("strlcpy: %zu\n", strlcpy(dst, src, 6));
		printf("src: |%s|\n", src);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	// printf("\n-----------------------------------------------------------\n\n");
	// {
	// 	errno = 0;
	// 	printf("\nft_printf: %d\n", ft_printf("%##v"));
	// 	printf("errno: %d - %s\n", errno, strerror(errno));
	// }
	// printf("\n");
	// {
	// 	errno = 0;
	// 	printf("\nprintf: %d\n", printf("%##v"));
	// 	printf("errno: %d - %s\n", errno, strerror(errno));
	// }
	printf("\n-----------------------------------------------------------\n\n");
	{
		char str[10] = "123456789";
		errno = 0;
		printf("ft_snprintf: %d\n", ft_snprintf(str, 10, "%##v"));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char str[10] = "123456789";
		errno = 0;
		printf("snprintf: %d\n", snprintf(str, 10, "%##v"));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n-----------------------------------------------------------\n\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("ft_snprintf: %d\n", ft_snprintf(str, 3, "%d", 123456789));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("snprintf: %d\n", snprintf(str, 3, "%d", 123456789));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n-----------------------------------------------------------\n\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("ft_snprintf: %d\n", ft_snprintf(str, 0, "%s", "123456789"));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("snprintf: %d\n", snprintf(str, 0, "%s", "123456789"));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n-----------------------------------------------------------\n\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("ft_snprintf: %d\n", ft_snprintf(str, 4, "%s", ""));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("snprintf: %d\n", snprintf(str, 4, "%s", ""));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n-----------------------------------------------------------\n\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("ft_snprintf: %d\n", ft_snprintf(str, 4, "%s%p", NULL, NULL));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("snprintf: %d\n", snprintf(str, 4, "%s%p", NULL, NULL));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n-----------------------------------------------------------\n\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("ft_snprintf: %d\n", ft_snprintf(str, 4, "%p", NULL));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("snprintf: %d\n", snprintf(str, 4, "%p", NULL));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n-----------------------------------------------------------\n\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("ft_snprintf: %d\n", ft_snprintf(str, 10, "%d", -1234567890));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("snprintf: %d\n", snprintf(str, 10, "%d", -1234567890));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n-----------------------------------------------------------\n\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("ft_snprintf: %d\n", ft_snprintf(str, 2, "%d", -1234567890));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char str[10] = "000000000";
		errno = 0;
		printf("snprintf: %d\n", snprintf(str, 2, "%d", -1234567890));
		printf("str: |%s|\n", str);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n-----------------------------------------------------------\n\n");
	{
		char src[20];
		char *dst = src + 3;
		ft_strlcpy(src, "123456789", 20);
		errno = 0;
		printf("ft_strlcat: %zu\n", ft_strlcat(dst, src, 20));
		printf("src: |%s|\n", src);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
	printf("\n");
	{
		char src[20];
		char *dst = src + 3;
		strlcpy(src, "123456789", 20);
		errno = 0;
		printf("strlcat: %zu\n", strlcat(dst, src, 20));
		printf("src: |%s|\n", src);
		printf("errno: %d - %s\n", errno, strerror(errno));
	}
}
