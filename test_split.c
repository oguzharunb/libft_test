#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "libft_test.h"

static void	free_split(char **arr)
{
	if (arr)
	{
		for (int i = 0; arr[i]; i++)
		{
			free(arr[i]);
		}
		free(arr);
	}
}

void	test_ft_split(void)
{
	char **result;

	// Test 1: Simple split
	result = ft_split("hello,world", ',');
	print_result(result != NULL && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0, "Test 1: Simple split");
	free_split(result);

	// Test 2: No delimiter
	result = ft_split("helloworld", ',');
	print_result(result != NULL && strcmp(result[0], "helloworld") == 0 && result[1] == NULL, "Test 2: No delimiter");
	free_split(result);

	// Test 3: Leading delimiter
	result = ft_split(",hello,world", ',');
	print_result(result != NULL && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0 && result[2] == NULL, "Test 3: Leading delimiter");
	free_split(result);

	// Test 4: Trailing delimiter
	result = ft_split("hello,world,", ',');
	print_result(result != NULL && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0 && result[2] == NULL, "Test 4: Trailing delimiter");
	free_split(result);

	// Test 5: Multiple consecutive delimiters
	result = ft_split("hello,,world", ',');
	print_result(result != NULL && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0 && result[2] == NULL, "Test 5: Multiple consecutive delimiters");
	free_split(result);

	// Test 6: Empty string
	result = ft_split("", ',');
	print_result(result != NULL && result[0] == NULL, "Test 6: Empty string");
	free_split(result);

	// Test 7: String with spaces
	result = ft_split("   hello   world   ", ' ');
	print_result(result != NULL && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0 && result[2] == NULL, "Test 7: String with spaces");
	free_split(result);

	// Test 8: String with multiple delimiters
	result = ft_split("a/b/c", '/');
	print_result(result != NULL && strcmp(result[0], "a") == 0 && strcmp(result[1], "b") == 0 && strcmp(result[2], "c") == 0 && result[3] == NULL, "Test 8: String with multiple delimiters");
	free_split(result);

	// Test 9: Only delimiters
	result = ft_split("///", '/');
	print_result(result != NULL && result[0] == NULL, "Test 9: Only delimiters");
	free_split(result);

	// Test 10: Special characters
	result = ft_split("hello!@#$world", '!');
	print_result(result != NULL && strcmp(result[0], "hello") == 0 && strcmp(result[1], "@#$world") == 0 && result[2] == NULL, "Test 10: Special characters");
	free_split(result);
}
