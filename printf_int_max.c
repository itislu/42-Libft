#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "inc/ft_printf.h"

int main() {
    size_t huge_size = (size_t)INT_MAX + 1000;  // Some amount above INT_MAX
    printf("Attempting to allocate and write %zu bytes\n", huge_size);
    
    // Attempt to allocate a huge buffer
    char *huge_buffer = malloc(huge_size);
    if (!huge_buffer) {
        printf("Failed to allocate buffer\n");
        return 1;
    }
    
    // Try to write a long string of 'x' characters into it
    int result = ft_snprintf(huge_buffer, huge_size, "hello%*c%d", INT_MAX - 6, 'x', 1000);
    // result = printf("hello%*c%d", INT_MAX - 6, 'x', 1000);
    
    printf("ft_snprintf returned: %d\n", result);
    printf("First few bytes: %.10s\n", huge_buffer);
    
    free(huge_buffer);
    return 0;
}
