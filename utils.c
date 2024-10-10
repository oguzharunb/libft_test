/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:08:56 by obastug           #+#    #+#             */
/*   Updated: 2024/10/10 13:43:44 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <stdio.h>

void	print_result(int condition, const char *test_name)
{
	if (condition)
	{
		printf(GREEN "[PASS] " RESET "%s\n", test_name);
	}
	else
	{
		printf(RED "[FAIL] " RESET "%s\n", test_name);
	}
}

void	run_function_tests(void (*f)(void), const char *function_name)
{
	printf("Running tests for %s\n", function_name);
	printf("--------------------\n");
	f();
	printf("--------------------\n\n");
}