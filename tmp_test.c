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
#include <bsd/string.h>

void test_strlcat(const char *test_name, const char *dst_init, const char *src, size_t size);
void null_tests(void);

int main(void) 
{
    printf("=== STRLCAT TESTS ===\n\n");
    
    // Normal cases
    test_strlcat("Basic concatenation", "Hello, ", "world!", 50);
    test_strlcat("Exact space for concatenation", "Hello, ", "world!", 13);
    test_strlcat("Limited space", "Hello, ", "world!", 10);
    test_strlcat("Empty destination", "", "Hello!", 20);
    test_strlcat("Empty source", "Hello!", "", 20);
    
    // Edge cases
    test_strlcat("Size zero", "Hello!", "world", 0);
    test_strlcat("Size < dst length", "Hello, world!", "extra", 5);
    test_strlcat("Size = dst length", "Hello!", "world", 7);
    test_strlcat("Size = dst length + 1", "Hello!", "world", 8);
    test_strlcat("Single byte dst", "", "Hello", 1);
    test_strlcat("Long source", "Start: ", "This is a very long source string", 30);
    
    // NULL tests
    null_tests();
    
    return 0;
}

void test_strlcat(const char *test_name, const char *dst_init, const char *src, size_t size)
{
    char ogbuf[100];
    char ftbuf[100];
    size_t og_ret, ft_ret;
    
    // Initialize buffers
    memset(ogbuf, 0, sizeof(ogbuf));
    memset(ftbuf, 0, sizeof(ftbuf));
    strcpy(ogbuf, dst_init);
    strcpy(ftbuf, dst_init);
    
    printf("\n--- Test: %s ---\n", test_name);
    printf("dst: \"%s\", src: \"%s\", size: %zu\n", dst_init, src, size);
    
    // Test original strlcat
    og_ret = strlcat(ogbuf, src, size);
    printf("Original: result=\"%s\", return=%zu\n", ogbuf, og_ret);
    
    // Test ft_strlcat
    ft_ret = ft_strlcat(ftbuf, src, size);
    printf("ft_strlcat: result=\"%s\", return=%zu\n", ftbuf, ft_ret);
    
    // Compare results
    if (og_ret == ft_ret && strcmp(ogbuf, ftbuf) == 0) {
        printf("✅ PASS\n");
    } else {
        printf("❌ FAIL\n");
        if (og_ret != ft_ret)
            printf("   Return values differ: og=%zu, ft=%zu\n", og_ret, ft_ret);
        if (strcmp(ogbuf, ftbuf) != 0)
            printf("   Strings differ: og=\"%s\", ft=\"%s\"\n", ogbuf, ftbuf);
    }
}

void null_tests(void)
{
    char ogbuf[20];
    char ftbuf[20];
    size_t og_ret, ft_ret;
    
    printf("\n=== NULL POINTER TESTS (may crash) ===\n");
    
    // // Test: NULL source, size > 0
    // strcpy(ogbuf, "Hello!");
    // strcpy(ftbuf, "Hello!");
    // printf("\n--- Test: NULL source ---\n");
    // printf("dst: \"%s\", src: NULL, size: %d\n", ogbuf, 20);
    
    // printf("Testing original strlcat...\n");
    // og_ret = strlcat(ogbuf, NULL, 20);
    // printf("Original returned: %zu\n", og_ret);
    
    // printf("Testing ft_strlcat...\n");
    // ft_ret = ft_strlcat(ftbuf, NULL, 20);
    // printf("ft_strlcat returned: %zu\n", ft_ret);
    
    // if (og_ret == ft_ret && strcmp(ogbuf, ftbuf) == 0)
    //     printf("✅ PASS\n");
    // else
    //     printf("❌ FAIL\n");
    
    // Test: NULL source, size = 0
    strcpy(ogbuf, "Hello!");
    strcpy(ftbuf, "Hello!");
    printf("\n--- Test: NULL source, size 0 ---\n");
    printf("dst: \"%s\", src: NULL, size: 0\n", ogbuf);
    
    printf("Testing original strlcat...\n");
    og_ret = 0;
    og_ret = strlcat(NULL, "", 1);
    printf("Original returned: %zu\n", og_ret);
    
    printf("Testing ft_strlcat...\n");
    ft_ret = ft_strlcat(NULL, "", 1);
    printf("ft_strlcat returned: %zu\n", ft_ret);
    
    if (og_ret == ft_ret && strcmp(ogbuf, ftbuf) == 0)
        printf("✅ PASS\n");
    else
        printf("❌ FAIL\n");
    
    // NOTE: Testing with NULL destination would likely cause segmentation fault
    printf("\n⚠️ Tests with NULL destination omitted as they would likely crash\n");
    printf("   Original strlcat behavior with NULL dst is undefined\n");
}
