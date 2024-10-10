/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:11:39 by obastug           #+#    #+#             */
/*   Updated: 2024/10/10 14:10:50 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"

void	print_result(int condition, const char *test_name);
void	test_ft_split(void);
void	test_ft_calloc(void);
void	test_ft_memchr(void);
void 	test_ft_atoi(void);
void	run_function_tests(void (*f)(void), const char *function_name);
#endif