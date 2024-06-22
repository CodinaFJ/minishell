/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:58:43 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/17 18:02:14by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_test_res(char *fun, t_rc rc)
{
	ft_printf("%s", fun);
	for (size_t i = 0; i < 6 - (ft_strlen(fun) / 8); i++)
		ft_printf("\t");
	if (rc == RC_OK)
	{
		ft_printf("%s", GREEN);
		ft_printf("OK");
	}
	else
	{
		ft_printf("%s", RED);
		switch (rc)
		{
		case RC_NULLPTR:
			ft_printf("NULL PTR");
			break;
		default:
		 	ft_printf("NOK");
			break;
		}
	}
	ft_printf("%s\n", RESET);
}

t_rc	assert_str(char *result, char *reference)
{
	t_rc	rc = RC_OK;
	
	rc = ft_strcmp(result, reference) == 0 ? rc : RC_NOK;
	if (rc == RC_NOK)
		ft_printf("\nExpected:\t%s\nResult:\t\t%s\n\n", reference, result);
	return (rc);
}

t_rc	assert_int(int result, int reference)
{
	t_rc	rc = RC_OK;
	
	rc = result == reference ? rc : RC_NOK;
	if (rc == RC_NOK)
		ft_printf("Expected:\t%d\nResult:\t%d\n", reference, result);
	return (rc);
}

t_rc	assert(t_bool expresion)
{
	t_rc	rc = RC_OK;
	
	rc = expresion == true? rc : RC_NOK;
	if (rc == RC_NOK)
		ft_printf("Expected:\ttrue\nResult:\tfalse\n");
	return (rc);
}

int	test_minishell(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	(void) envp;
	test_automata_exp(envp);
	test_automata_lexer(envp);
	test_environment(envp);
	return (0);
}