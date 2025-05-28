#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#ifndef FT_FIRST
# define FT_FIRST 0
#endif

void test_and_compare(char *test_name, char *str1, char *str2, size_t size)
{
    size_t ret1;
	size_t ret2;

    printf("\n=== %s ===\n", test_name);
#if FT_FIRST
    // Test ft_strlcat
    printf("\nft_strlcat:\n");
    printf("Before: %s\n", str2);
    ret2 = ft_strlcat(str2 + 5, str2, size);
    printf("After:  %s\n", str2);
    printf("Return: %zu\n", ret2);
#endif
    // Test original strlcat
    printf("\nOriginal strlcat:\n");
    printf("Before: %s\n", str1);
    ret1 = strlcat(str1 + 5, str1, size);
    printf("After:  %s\n", str1);
    printf("Return: %zu\n", ret1);
#if !FT_FIRST
    // Test ft_strlcat
    printf("\nft_strlcat:\n");
    printf("Before: %s\n", str2);
    ret2 = ft_strlcat(str2 + 5, str2, size);
    printf("After:  %s\n", str2);
    printf("Return: %zu\n", ret2);
#endif
    // Compare results
    printf("\nResults match: %s\n", 
        (strcmp(str1, str2) == 0 && ret1 == ret2) ? "YES" : "NO");
    if (strcmp(str1, str2) != 0)
        printf("String mismatch!\n");
    if (ret1 != ret2)
        printf("Return value mismatch! (%zu vs %zu)\n", ret1, ret2);
}

void run_overlap_tests(void)
{
    // Test 1: Complete overlap (src equals dst)
    // char orig1[11] = "123456789";
    // char ft1[11] = "123456789";
    // orig1[10] = '\0';
    // ft1[10] = '\0';
    char *mem1 = calloc(100, 1);
    char *orig1 = mem1;
    char *ft1 = mem1 + 50;
    strlcpy(orig1, "123456789", 11);
    strlcpy(ft1, "123456789", 11);
    test_and_compare("Complete overlap", orig1, ft1, 10);
    free(mem1);

    // Test 2: Partial overlap (src starts in middle)
    // char orig2[11] = "123456789";
    // char ft2[11] = "123456789";
    // orig2[10] = '\0';
    // ft2[10] = '\0';
    char *mem2 = calloc(100, 1);
    char *orig2 = mem2;
    char *ft2 = mem2 + 50;
    strlcpy(orig2, "123456789", 11);
    strlcpy(ft2, "123456789", 11);
    test_and_compare("Partial overlap (middle)", orig2, ft2, 8);
    free(mem2);

    // Test 3: Partial overlap with limited size
    // char orig3[11] = "123456789";
    // char ft3[11] = "123456789";
    // orig3[10] = '\0';
    // ft3[10] = '\0';
    char *mem3 = calloc(100, 1);
    char *orig3 = mem3;
    char *ft3 = mem3 + 50;
    strlcpy(orig3, "123456789", 11);
    strlcpy(ft3, "123456789", 11);
    test_and_compare("Partial overlap (limited size)", orig3, ft3, 20);
    free(mem3);

    // Test 4: Edge case - size 1
    // char orig4[11] = "123456789";
    // char ft4[11] = "123456789";
    // orig4[10] = '\0';
    // ft4[10] = '\0';
    char *mem4 = calloc(100, 1);
    char *orig4 = mem4;
    char *ft4 = mem4 + 50;
    strlcpy(orig4, "123456789", 11);
    strlcpy(ft4, "123456789", 11);
    test_and_compare("Edge case - size 1", orig4, ft4, 1);
    free(mem4);

    // Test 5: Edge case - size 0
    // char orig5[11] = "123456789";
    // char ft5[11] = "123456789";
    // orig5[10] = '\0';
    // ft5[10] = '\0';
    char *mem5 = calloc(100, 1);
    char *orig5 = mem5;
    char *ft5 = mem5 + 50;
    strlcpy(orig5, "123456789", 11);
    strlcpy(ft5, "123456789", 11);
    test_and_compare("Edge case - size 0", orig5, ft5, 0);
    free(mem5);

    // Test 6: Partial overlap (offset by 1)
    // char orig6[11] = "123456789";
    // char ft6[11] = "123456789";
    // orig6[10] = '\0';
    // ft6[10] = '\0';
    char *mem6 = calloc(100, 1);
    char *orig6 = mem6;
    char *ft6 = mem6 + 50;
    strlcpy(orig6, "123456789", 11);
    strlcpy(ft6, "123456789", 11);
    test_and_compare("Partial overlap (offset 1)", orig6, ft6, sizeof(orig6));
    free(mem6);

    // Test 7: Long string overlap
    // char orig7[] = "This is a much longer string to test overlap behavior";
    // char ft7[] = "This is a much longer string to test overlap behavior";
    // orig7[sizeof(orig7) - 1] = '\0';
    // ft7[sizeof(ft7) - 1] = '\0';
    char *mem7 = calloc(500, 1);
    char *orig7 = mem7;
    char *ft7 = mem7 + 200;
    strlcpy(orig7, "This is a much longer string to test overlap behavior", 54);
    strlcpy(ft7, "This is a much longer string to test overlap behavior", 54);
    test_and_compare("Long string overlap", orig7, ft7, 50);
    free(mem7);

    // Test 8: Long string overlap
    // char orig8[] = "This is a much longer string to test overlap behavior";
    // char ft8[] = "This is a much longer string to test overlap behavior";
    // orig8[sizeof(orig8) - 1] = '\0';
    // ft8[sizeof(ft8) - 1] = '\0';
    char *mem8 = calloc(500, 1);
    char *orig8 = mem8;
    char *ft8 = mem8 + 200;
    strlcpy(orig7, "my_test", 5);
    strlcpy(ft7, "my_test", 5);
    test_and_compare("Long string overlap", orig8, ft8, 50);
    free(mem8);
}

int main(void)
{
    printf("Comparing ft_strlcat with original strlcat for overlapping cases:\n");
    run_overlap_tests();
    return (0);
}
