#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void *ft_calloc(size_t nelem, size_t elsize); // Assume this function is defined elsewhere

// ANSI color codes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void test_ft_calloc() {
    void *ptr;

    // Test 1: Allocate 0 elements
    ptr = ft_calloc(0, 10);
    printf("ft_calloc Test 1: %s\n", ptr == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);

    // Test 2: Allocate 10 elements of size 1 byte
    ptr = ft_calloc(10, 1);
    printf("ft_calloc Test 2: %s\n", ptr != NULL && memcmp(ptr, "\0\0\0\0\0\0\0\0\0\0", 10) == 0 ? GREEN "Passed" RESET : RED "Failed" RESET);
    free(ptr);

    // Test 3: Allocate 5 elements of size 4 bytes
    ptr = ft_calloc(5, 4);
    printf("ft_calloc Test 3: %s\n", ptr != NULL && memcmp(ptr, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 20) == 0 ? GREEN "Passed" RESET : RED "Failed" RESET);
    free(ptr);

    // Test 4: Allocate 1 element of size 0 bytes
    ptr = ft_calloc(1, 0);
    printf("ft_calloc Test 4: %s\n", ptr == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);

    // Test 5: Large allocation
    ptr = ft_calloc(1000, 1000);
    printf("ft_calloc Test 5: %s\n", ptr != NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
    free(ptr);

    // Test 6: Memory check
    ptr = ft_calloc(10, sizeof(int));
    if (ptr != NULL) {
        int *int_ptr = (int *)ptr;
        int passed = 1;
        for (size_t i = 0; i < 10; i++) {
            if (int_ptr[i] != 0) {
                passed = 0;
                break;
            }
        }
        printf("ft_calloc Test 6: %s\n", passed ? GREEN "Passed" RESET : RED "Failed" RESET);
        free(ptr);
    } else {
        printf("ft_calloc Test 6: %s\n", RED "Failed (NULL pointer)" RESET);
    }

    // Test 7: Allocate multiple elements
    ptr = ft_calloc(10, sizeof(char));
    printf("ft_calloc Test 7: %s\n", ptr != NULL && memcmp(ptr, "\0\0\0\0\0\0\0\0\0\0", 10) == 0 ? GREEN "Passed" RESET : RED "Failed" RESET);
    free(ptr);

    // Test 8: Large element size
    ptr = ft_calloc(1, 1000000);
    printf("ft_calloc Test 8: %s\n", ptr != NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
    free(ptr);

    // Test 9: Check for memory leak
    ptr = ft_calloc(1, 1);
    if (ptr) {
        free(ptr);
        printf("ft_calloc Test 9: " GREEN "Passed" RESET "\n");
    } else {
        printf("ft_calloc Test 9: " RED "Failed" RESET "\n");
    }

    // Test 10: Negative size (if applicable)
    // Uncomment the following line if your ft_calloc handles negative sizes.
    // ptr = ft_calloc(1, (size_t)-1);
    // printf("ft_calloc Test 10: %s\n", ptr == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);

    // Test 11: Zero total allocation
    ptr = ft_calloc(0, 0);
    printf("ft_calloc Test 11: %s\n", ptr == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);

    // Test 12: Large nelem and elsize
    ptr = ft_calloc(10000, 10000);
    printf("ft_calloc Test 12: %s\n", ptr != NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
    free(ptr);

    // Test 13: Checking pointer arithmetic
    ptr = ft_calloc(10, sizeof(int));
    if (ptr) {
        int *int_ptr = (int *)ptr;
        printf("ft_calloc Test 13: %s\n", int_ptr[1] == 0 ? GREEN "Passed" RESET : RED "Failed" RESET);
        free(ptr);
    } else {
        printf("ft_calloc Test 13: %s\n", RED "Failed (NULL pointer)" RESET);
    }

    // Test 14: Sequential allocations
    for (int i = 0; i < 5; i++) {
        ptr = ft_calloc(10, sizeof(char));
        printf("ft_calloc Test 14-%d: %s\n", i + 1, ptr != NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
        free(ptr);
    }

    // Test 15: Check for NULL pointers
    ptr = ft_calloc(10, sizeof(int));
    printf("ft_calloc Test 15: %s\n", ptr != NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
    free(ptr);

    // Test 16: Free after allocation
    ptr = ft_calloc(10, sizeof(int));
    if (ptr) {
        free(ptr);
        printf("ft_calloc Test 16: " GREEN "Passed" RESET "\n");
    } else {
        printf("ft_calloc Test 16: " RED "Failed (NULL pointer)" RESET "\n");
    }

    // Test 17: Repeated calls
    for (int i = 0; i < 5; i++) {
        ptr = ft_calloc(1, sizeof(int));
        printf("ft_calloc Test 17-%d: %s\n", i + 1, ptr != NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
        free(ptr);
    }

    // Test 18: Allocate for struct
    typedef struct { int x; int y; } Point;
    Point *points = ft_calloc(10, sizeof(Point));
    printf("ft_calloc Test 18: %s\n", points != NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
    free(points);

    // Test 19: Allocation exceeding limits
    ptr = ft_calloc(SIZE_MAX, 1);
    printf("ft_calloc Test 19: %s\n", ptr == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);

    // Test 20: Initialize a large array
    ptr = ft_calloc(1000, sizeof(Point));
    if (ptr) {
        Point *point_array = (Point *)ptr;
        printf("ft_calloc Test 20: %s\n", point_array[0].x == 0 && point_array[0].y == 0 ? GREEN "Passed" RESET : RED "Failed" RESET);
        free(ptr);
    } else {
        printf("ft_calloc Test 20: %s\n", RED "Failed (NULL pointer)" RESET);
    }
}

int main() {
    test_ft_calloc();
    return 0;
}
