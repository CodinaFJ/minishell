/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:02:49 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/17 17:58:55y jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "../../include/minishell.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;35m"
# define RESET "\033[0m"

void	test_automata_exp(void *ctx);
void	test_automata_lexer(void *ctx);
void	test_environment(void *ctx);
void	test_export(void* ctx);
void	test_unset(void *envp);
void	test_env(void *envp);
void	print_test_res(char *fun, t_rc rc);

t_rc	assert_str(char *result, char *reference);
t_rc	assert_int(int result, int reference);
t_rc	assert(t_bool expresion);

#endif // !TEST_H