#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "libft_test.h"

void test_ft_calloc()
{
	void *ptr;

	// Test 1: Allocate 0 elements
	ptr = ft_calloc(0, 10);
	print_result(ptr == NULL, "Test 1: Allocate 0 elements");

	// Test 2: Allocate 10 elements of size 1 byte
	ptr = ft_calloc(10, 1);
	print_result(ptr != NULL && memcmp(ptr, "\0\0\0\0\0\0\0\0\0\0", 10) == 0, "Test 2: Allocate 10 elements of size 1 byte");
	free(ptr);

	// Test 3: Allocate 5 elements of size 4 bytes
	ptr = ft_calloc(5, 4);
	print_result(ptr != NULL && memcmp(ptr, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 20) == 0, "Test 3: Allocate 5 elements of size 4 bytes");
	free(ptr);

	// Test 4: Allocate 1 element of size 0 bytes
	ptr = ft_calloc(1, 0);
	print_result(ptr == NULL, "Test 4: Allocate 1 element of size 0 bytes");

	// Test 5: Large allocation
	ptr = ft_calloc(1000, 1000);
	int	i = 0;
	while (i < 1000000)
	{
		if (((char *)ptr)[i] != 0)
		{
			break ;
		}
		i++;
	}
	if (i == 1000000)
		print_result(1, "Test 5: Large allocation");
	else
		print_result(0, "Test 5: Large allocation");
	free(ptr);

	// Test 6: Memory check
	ptr = ft_calloc(10, sizeof(int));
	if (ptr != NULL)
	{
		int *int_ptr = (int *)ptr;
		int passed = 1;
		for (size_t i = 0; i < 10; i++)
		{
			if (int_ptr[i] != 0)
			{
				passed = 0;
				break;
			}
		}
		print_result(passed, "Test 6: Memory check");
		free(ptr);
	}

	// Test 7: Allocate multiple elements
	ptr = ft_calloc(10, sizeof(char));
	print_result(ptr != NULL && memcmp(ptr, "\0\0\0\0\0\0\0\0\0\0", 10) == 0, "Test 7: Allocate multiple elements");
	free(ptr);

	// Test 8: Large element size
	ptr = ft_calloc(1, 1000000);
	i = 0;
	int tester = 0;
	while (i < 1000000)
	{
		if (((char *)ptr)[i] != 0)
		{
			tester = 1;
		}
		i++;
	}
	print_result(tester == 0, "Test 8: Large element size");
	free(ptr);

	// Test 9: Check for memory leak
	ptr = ft_calloc(1, 1);
	if (ptr)
	{
		free(ptr);
		print_result(1, "Test 9: Check for memory leak");
	}
	else
		print_result(0, "Test 9: Check for memory leak");

	// Test 10: Negative size (if applicable)
	// Uncomment the following line if your ft_calloc handles negative sizes.
	// ptr = ft_calloc(1, (size_t)-1);
	// printf("ft_calloc Test 10: %s\n", ptr == NULL ? GREEN "Passed" RESET : RED "Failed" RESET);

	// Test 11: Zero total allocation
	ptr = ft_calloc(0, 0);
	print_result(ptr == NULL, "Test 11: Zero total allocation");

	// Test 12: Large nelem and elsize
	ptr = ft_calloc(10000, 10000);
	i = 0;
	tester = 0;
	while (i < 100000000)
	{
		if (((char *)ptr)[i] != 0)
		{
			tester = 1;
		}
		i++;
	}
	print_result(tester == 0, "Test 12: Large nelem and elsize");
	free(ptr);

	// Test 13: Checking pointer arithmetic
	ptr = ft_calloc(10, sizeof(int));
	if (ptr)
	{
		int *int_ptr = (int *)ptr;
		print_result(int_ptr[1] == 0, "Test 13: Checking pointer arithmetic");
		free(ptr);
	}
	else
		print_result(0, "Test 13: Checking pointer arithmetic");

	// Test 14: Sequential allocations
	for (int i = 0; i < 10; i++)
	{
		ptr = ft_calloc(1, sizeof(int));
		if (ptr)
		{
			free(ptr);
			print_result(1, "Test 14: Sequential allocations");
		}
		else
		{
			print_result(0, "Test 14: Sequential allocations");
		}
	}

	// Test 15: Check for NULL pointers
	ptr = ft_calloc(10, sizeof(int));
	print_result(ptr != NULL, "Test 15: Check for NULL pointers");
	free(ptr);

	// Test 16: Free after allocation
	ptr = ft_calloc(10, sizeof(int));
	if (ptr)
	{
		free(ptr);
		print_result(1, "Test 16: Free after allocation");
	}
	else
	{
		print_result(0, "Test 16: Free after allocation");
	}

	// Test 17: Repeated calls
	for (int i = 0; i < 5; i++)
	{
		ptr = ft_calloc(1, sizeof(int));
		print_result(ptr != NULL, "Test 17: Repeated calls");
		free(ptr);
	}

	// Test 18: Allocate for struct
	typedef struct
	{
		int x;
		int y;
	} Point;
	Point *points = ft_calloc(10, sizeof(Point));
	print_result(points != NULL, "Test 18: Allocate for struct");
	free(points);

	// Test 19: Allocation exceeding limits
	ptr = ft_calloc(SIZE_MAX, 1);
	print_result(ptr == NULL, "Test 19: Allocation exceeding limits");

	// Test 20: Initialize a large array
	ptr = ft_calloc(1000, sizeof(Point));
	if (ptr)
	{
		Point *point_array = (Point *)ptr;
		print_result(point_array[0].x == 0 && point_array[0].y == 0 && point_array[999].x == 0 && point_array[999].y == 0, "Test 20: Initialize a large array");
		free(ptr);
	}
	else
		print_result(0, "Test 20: Initialize a large array");
}
