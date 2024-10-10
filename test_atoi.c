#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "libft_test.h"

// Test cases for ft_atoi
void test_ft_atoi()
{
	// Test 1: Basic positive number
	print_result(ft_atoi("123") == 123, "Test 1: Basic positive number");

	// Test 2: Basic negative number
	print_result(ft_atoi("-123") == -123, "Test 2: Basic negative number");

	// Test 3: Leading spaces
	print_result(ft_atoi("   456") == 456, "Test 3: Leading spaces");

	// Test 4: Trailing non-numeric characters (should stop at first non-numeric)
	print_result(ft_atoi("789abc") == 789, "Test 4: Trailing non-numeric characters");

	// Test 5: Leading + sign
	print_result(ft_atoi("+42") == 42, "Test 5: Leading + sign");

	// Test 6: Zero string
	print_result(ft_atoi("0") == 0, "Test 6: Zero string");

	// Test 7: Empty string (should return 0)
	print_result(ft_atoi("") == 0, "Test 7: Empty string");

	// Test 8: String with only spaces
	print_result(ft_atoi("    ") == 0, "Test 8: String with only spaces");

	// Test 9: Large positive number
	print_result(ft_atoi("2147483647") == 2147483647, "Test 9: Large positive number");

	// Test 10: Large negative number
	print_result(ft_atoi("-2147483648") == -2147483648, "Test 10: Large negative number");

	// Test 11: Overflow case (should return INT_MAX or INT_MIN, depending on implementation)
	print_result(ft_atoi("9223372036854775807") == -1, "Test 11: Overflow case (positive)");

	// Test 12: Underflow case
	print_result(ft_atoi("-9223372036854775808") == 0, "Test 12: Underflow case (negative)");

	// Test 13: Invalid input (no digits)
	print_result(ft_atoi("abc") == 0, "Test 13: Invalid input (no digits)");

	// Test 14: Mixed valid and invalid characters
	print_result(ft_atoi("42abc") == 42, "Test 14: Mixed valid and invalid characters");

	// Test 15: Number with leading zeros
	print_result(ft_atoi("00001234") == 1234, "Test 15: Number with leading zeros");

	// Test 16: Number with spaces in between (should stop at first invalid character)
	print_result(ft_atoi("12 34") == 12, "Test 16: Number with spaces in between");

	// Test 17: Number starting with non-numeric characters
	print_result(ft_atoi("abc42") == 0, "Test 17: Number starting with non-numeric characters");

	// Test 18: Only a sign character
	print_result(ft_atoi("+") == 0, "Test 18: Only a sign character");

	// Test 19: Only a negative sign character
	print_result(ft_atoi("-") == 0, "Test 19: Only a negative sign character");

	// Test 20: Max value of int + 1 (should return INT_MAX)
	print_result(ft_atoi("2147483648") == -2147483648, "Test 20: Max value of int + 1");
}
