/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:23:05 by obastug           #+#    #+#             */
/*   Updated: 2024/10/10 18:01:20 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include <string.h>
int main()
{
	run_function_tests(test_ft_calloc, "ft_calloc");
	run_function_tests(test_ft_split, "ft_split");
	run_function_tests(test_ft_memchr, "ft_memchr");
	run_function_tests(test_ft_atoi, "ft_atoi");
	run_function_tests(test_ft_bzero, "ft_bzero");
	return 0;
}