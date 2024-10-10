#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "libft_test.h"

// Test cases for ft_memchr
void test_ft_memchr() {
    char str1[] = "hello";
    char str2[] = "banana";
    unsigned char data1[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    unsigned char data2[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE};

    // Test 1: Basic case (character found early)
    print_result(ft_memchr(str1, 'e', 5) == &str1[1], "Test 1: Basic case (character found early)");

    // Test 2: Character not found
    print_result(ft_memchr(str1, 'x', 5) == NULL, "Test 2: Character not found");

    // Test 3: Character at the end of the range
    print_result(ft_memchr(str1, 'o', 5) == &str1[4], "Test 3: Character at the end of the range");

    // Test 4: Character at the first position
    print_result(ft_memchr(str1, 'h', 5) == &str1[0], "Test 4: Character at the first position");

    // Test 5: Null character in string
    print_result(ft_memchr(str1, '\0', 6) == &str1[5], "Test 5: Null character in string");

    // Test 6: Null character not in range
    print_result(ft_memchr(str1, '\0', 5) == NULL, "Test 6: Null character not in range");

    // Test 7: Empty string
    print_result(ft_memchr("", 'a', 0) == NULL, "Test 7: Empty string");

    // Test 8: Non-printable character
    char str3[] = "a\0b";
    print_result(ft_memchr(str3, '\0', 3) == &str3[1], "Test 8: Non-printable character");

    // Test 9: Non-printable character not found
    print_result(ft_memchr(str3, '\n', 3) == NULL, "Test 9: Non-printable character not found");

    // Test 10: Searching in binary data
    print_result(ft_memchr(data1, 0x03, 5) == &data1[2], "Test 10: Searching in binary data");

    // Test 11: Character not found in binary data
    print_result(ft_memchr(data1, 0x06, 5) == NULL, "Test 11: Character not found in binary data");

    // Test 12: Null input pointer
    print_result(ft_memchr(NULL, 'a', 0) == NULL, "Test 12: Null input pointer");

    // Test 13: Multiple occurrences of character
    print_result(ft_memchr(str2, 'a', 6) == &str2[1], "Test 13: Multiple occurrences of character");

    // Test 14: Negative character value
    print_result(ft_memchr(str1, -123, 5) == NULL, "Test 14: Negative character value");

    // Test 15: Large n exceeding string length
    print_result(ft_memchr(str1, 'o', 100) == &str1[4], "Test 15: Large n exceeding string length");

    // Test 16: Large n with no match
    print_result(ft_memchr(str1, 'z', 100) == NULL, "Test 16: Large n with no match");

    // Test 17: Partial search within range
    print_result(ft_memchr(str1, 'o', 4) == NULL, "Test 17: Partial search within range");

    // Test 18: Empty array
    char empty[] = "";
    print_result(ft_memchr(empty, 'x', 0) == NULL, "Test 18: Empty array");

    // Test 19: Array of identical bytes
    unsigned char data3[] = {0xAA, 0xAA, 0xAA, 0xAA};
    print_result(ft_memchr(data3, 0xAA, 4) == &data3[0], "Test 19: Array of identical bytes");

    // Test 20: Searching mixed bytes in binary data
    print_result(ft_memchr(data2, 0xDD, 5) == &data2[3], "Test 20: Searching mixed bytes in binary data");
}
