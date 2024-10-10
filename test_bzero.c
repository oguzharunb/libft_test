#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "libft_test.h"

void test_ft_bzero()
{
	char buffer[100];

	// Test 1: Zero out a string buffer
	strcpy(buffer, "Hello, World!");
	ft_bzero(buffer, 6);
	print_result(memcmp(buffer, "\0\0\0\0\0\0 World!", 13) == 0, "Test 1: Zero out a string buffer");

	// Test 2: Zero out a portion of the buffer
	strcpy(buffer, "Test String");
	ft_bzero(buffer + 5, 6);
	print_result(memcmp(buffer, "Test \0\0\0\0\0\0", 12) == 0, "Test 2: Zero out a portion of the buffer");

	// Test 3: Zero out the entire buffer
	strcpy(buffer, "Full buffer");
	ft_bzero(buffer, strlen(buffer));
	print_result(memcmp(buffer, "\0\0\0\0\0\0\0\0\0\0\0", 11) == 0, "Test 3: Zero out the entire buffer");

	// Test 4: Zero out an empty buffer
	strcpy(buffer, "");
	ft_bzero(buffer, 0);
	print_result(buffer[0] == '\0', "Test 4: Zero out an empty buffer");

	// Test 5: Zero out an integer array
	int int_arr[5] = {1, 2, 3, 4, 5};
	ft_bzero(int_arr, 5 * sizeof(int));
	int passed = 1;
	for (int i = 0; i < 5; i++)
	{
		if (int_arr[i] != 0)
		{
			passed = 0;
			break;
		}
	}
	print_result(passed, "Test 5: Zero out an integer array");

	// Test 6: Zero out part of a struct
	typedef struct {
		int x;
		int y;
	} Point;

	Point point = {42, 24};
	ft_bzero(&point.x, sizeof(int));
	print_result(point.x == 0 && point.y == 24, "Test 6: Zero out part of a struct");

	// Test 7: Zero out a large buffer
	char large_buffer[1000];
	memset(large_buffer, 'A', 1000);
	ft_bzero(large_buffer, 1000);
	passed = 1;
	for (int i = 0; i < 1000; i++)
	{
		if (large_buffer[i] != '\0')
		{
			passed = 0;
			break;
		}
	}
	print_result(passed, "Test 7: Zero out a large buffer");

	// Test 8: Zeroing zero bytes
	strcpy(buffer, "Zero length test");
	ft_bzero(buffer, 0);
	print_result(strcmp(buffer, "Zero length test") == 0, "Test 8: Zeroing zero bytes");

	// Test 9: Zero first element only
	strcpy(buffer, "Test buffer");
	ft_bzero(buffer, 1);
	print_result(buffer[0] == '\0' && strcmp(buffer + 1, "est buffer") == 0, "Test 9: Zero first element only");

	// Test 10: Check NULL pointer (should not crash, no operation)
	ft_bzero(NULL, 0);
	print_result(1, "Test 10: Check NULL pointer");

	// Test 11: Zero out float array
	float float_arr[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	ft_bzero(float_arr, 5 * sizeof(float));
	passed = 1;
	for (int i = 0; i < 5; i++)
	{
		if (float_arr[i] != 0)
		{
			passed = 0;
			break;
		}
	}
	print_result(passed, "Test 11: Zero out float array");

	// Test 12: Zero out double array
	double double_arr[3] = {1.11, 2.22, 3.33};
	ft_bzero(double_arr, 3 * sizeof(double));
	passed = 1;
	for (int i = 0; i < 3; i++)
	{
		if (double_arr[i] != 0)
		{
			passed = 0;
			break;
		}
	}
	print_result(passed, "Test 12: Zero out double array");

	// Test 13: Zero struct array
	Point point_arr[10];
	for (int i = 0; i < 10; i++)
	{
		point_arr[i].x = i;
		point_arr[i].y = i * 2;
	}
	ft_bzero(point_arr, 10 * sizeof(Point));
	passed = 1;
	for (int i = 0; i < 10; i++)
	{
		if (point_arr[i].x != 0 || point_arr[i].y != 0)
		{
			passed = 0;
			break;
		}
	}
	print_result(passed, "Test 13: Zero struct array");

	// Test 14: Zeroing a single byte
	char single_byte = 'A';
	ft_bzero(&single_byte, 1);
	print_result(single_byte == '\0', "Test 14: Zeroing a single byte");
}
