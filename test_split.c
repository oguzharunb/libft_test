#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char **ft_split(char const *s, char c); // Assume this function is defined elsewhere

// ANSI color codes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void free_split(char **arr) {
    if (arr) {
        for (int i = 0; arr[i]; i++) {
            free(arr[i]);
        }
        free(arr);
    }
}

void test_ft_split() {
    char **result;

    // Test 1: Simple split
    result = ft_split("hello,world", ',');
    printf("ft_split Test 1: %s\n", result != NULL && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0 ? GREEN "Passed" RESET : RED "Failed" RESET);
    free_split(result);

    // Test 2: No delimiter
    result = ft_split("helloworld", ',');
    printf("ft_split Test 2: %s\n", result != NULL && strcmp(result[0], "helloworld") == 0 && result[1] == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
    free_split(result);

    // Test 3: Leading delimiter
    result = ft_split(",hello,world", ',');
    printf("ft_split Test 3: %s\n", result != NULL && strcmp(result[0], "") == 0 && strcmp(result[1], "hello") == 0 && strcmp(result[2], "world") == 0 ? GREEN "Passed" RESET : RED "Failed" RESET);
    free_split(result);

    // Test 4: Trailing delimiter
    result = ft_split("hello,world,", ',');
    printf("ft_split Test 4: %s\n", result != NULL && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0 && strcmp(result[2], "") == 0 ? GREEN "Passed" RESET : RED "Failed" RESET);
    free_split(result);

    // Test 5: Multiple consecutive delimiters
    result = ft_split("hello,,world", ',');
    printf("ft_split Test 5: %s\n", result != NULL && strcmp(result[0], "hello") == 0 && strcmp(result[1], "") == 0 && strcmp(result[2], "world") == 0 ? GREEN "Passed" RESET : RED "Failed" RESET);
    free_split(result);

    // Test 6: Empty string
    result = ft_split("", ',');
    printf("ft_split Test 6: %s\n", result != NULL && result[0] == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
    free_split(result);

    // Test 7: String with spaces
    result = ft_split("   hello   world   ", ' ');
    printf("ft_split Test 7: %s\n", result != NULL && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0 && result[2] == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
    free_split(result);

    // Test 8: String with multiple delimiters
    result = ft_split("a/b/c", '/');
    printf("ft_split Test 8: %s\n", result != NULL && strcmp(result[0], "a") == 0 && strcmp(result[1], "b") == 0 && strcmp(result[2], "c") == 0 && result[3] == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
    free_split(result);

    // Test 9: Only delimiters
    result = ft_split("///", '/');
    printf("ft_split Test 9: %s\n", result != NULL && strcmp(result[0], "") == 0 && strcmp(result[1], "") == 0 && strcmp(result[2], "") == 0 && result[3] == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
    free_split(result);

    // Test 10: Special characters
    result = ft_split("hello!@#$world", '!');
    printf("ft_split Test 10: %s\n", result != NULL && strcmp(result[0], "hello") == 0 && strcmp(result[1], "@#$world") == 0 && result[2] == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);
    free_split(result);
}

int main() {
    test_ft_split();
    return 0;
}
