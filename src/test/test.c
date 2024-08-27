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
	printf("%s", fun);
	for (size_t i = 0; i < 6 - (ft_strlen(fun) / 8); i++)
		printf("\t");
	if (rc == RC_OK)
	{
		printf("%s", GREEN);
		printf("OK");
	}
	else
	{
		printf("%s", RED);
		switch (rc)
		{
		case RC_NULLPTR:
			printf("NULL PTR");
			break ;
		default:
			printf("NOK");
			break ;
		}
	}
	printf("%s\n", RESET);
}

t_rc	assert_str(char *result, char *reference)
{
	t_rc	rc;

	rc = RC_OK;
	if (result == NULL && reference != NULL)
	{
		printf("\nExpected:\t%s\nResult:\t\t%s\n\n", reference, result);
		return (RC_NOK);
	}
	else if (result != NULL && reference == NULL)
	{
		printf("\nExpected:\t%s\nResult:\t\t%s\n\n", reference, result);
		return (RC_NOK);
	}
	else if (result == NULL && reference == NULL)
		return (RC_OK);
	rc = ft_strcmp(result, reference) == 0 ? rc : RC_NOK;
	if (rc == RC_NOK)
		printf("\nExpected:\t%s\nResult:\t\t%s\n\n", reference, result);
	return (rc);
}

t_rc	assert_int(int result, int reference)
{
	t_rc	rc;

	rc = RC_OK;
	rc = result == reference ? rc : RC_NOK;
	if (rc == RC_NOK)
		printf("Expected:\t%d\nResult:\t%d\n", reference, result);
	return (rc);
}

t_rc	assert(t_bool expresion)
{
	t_rc	rc;

	rc = RC_OK;
	rc = expresion == true ? rc : RC_NOK;
	if (rc == RC_NOK)
		printf("Expected:\ttrue\nResult:\tfalse\n");
	return (rc);
}

int	test_minishell(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	test_automata_exp(envp);
	test_automata_lexer(envp);
	test_environment(envp);
	test_export(envp);
	test_unset(envp);
	test_env(envp);
	return (0);
}