/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_automata_exp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:11:59 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/17 18: by jcodina-	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/**
 * test_automata_exp_init
 * 
 * test initialization of automata
 * expanser
 */
t_rc	test_automata_exp_init(void *ctx)
{
	t_rc			rc = RC_OK;
	t_automata_exp	*automata;
	t_minishell_ctx *mini_ctx;

	automata = automata_exp_init();
	rc = automata != NULL ? rc : RC_NOK;
	rc = automata->alphabet != NULL ? rc : RC_NOK;
	rc = ft_strs_rows((const char **) automata->alphabet) != 0 ? rc : RC_NOK;
	rc = automata->errors != NULL ? rc : RC_NOK;
	mini_ctx = (t_minishell_ctx *) ctx;
	mini_ctx->automata_expander = automata;
	return(rc);
}

/**
 * test_automata_exp_null_parses
 * 
 * test that null parses give null result
 */
t_rc	test_automata_exp_null_parses(void *ctx)
{
	t_rc			rc = RC_OK;
	char			*str_res;
	t_minishell_ctx *mini_ctx = (t_minishell_ctx *) ctx;

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx, "");
	rc = assert_str(str_res, "");
	free(str_res);

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx, NULL);
	rc = str_res == NULL ? rc : RC_NOK;
	return(rc);
}

/**
 * test_automata_exp_empty_vars
 * 
 * test vars that are not found
 */
t_rc	test_automata_exp_empty_vars(void *ctx)
{
	t_rc			rc = RC_OK;
	char			*str_res;
	t_minishell_ctx *mini_ctx = (t_minishell_ctx *) ctx;

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "foo$\"bar\"");
	rc = assert_str(str_res, "foo\"bar\"");
	free(str_res);

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "foo$bar");
	rc = assert_str(str_res, "foo");
	free(str_res);
	
	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "foo$b\"ar\"");
	rc = assert_str(str_res, "foo\"ar\"");
	free(str_res);

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "$foobar");
	rc = assert_str(str_res, "");
	free(str_res);

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "foo$b$bar");
	rc = assert_str(str_res, "foo");
	free(str_res);
	return(rc);
}

/**
 * test_automata_exp_real_vars
 * 
 * test real variables
 */
t_rc	test_automata_exp_real_vars(void *ctx)
{
	t_rc			rc = RC_OK;
	char			*str_res;
	t_minishell_ctx *mini_ctx = (t_minishell_ctx *) ctx;

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "$HOME");
	rc = assert_str(str_res, "/home/");
	free(str_res);

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "$USR");
	rc = assert_str(str_res, "javier");
	free(str_res);

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "hola $USR esta en $HOME");
	rc = assert_str(str_res, "hola javier esta en /home/");
	free(str_res);

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "$USR$HOME");
	rc = assert_str(str_res, "javier/home/");
	free(str_res);

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "a$USER$HOME");
	rc = assert_str(str_res, "a/home/");
	free(str_res);

	return(rc);
}

/**
 * test_automata_exp_quotes
 * 
 * test real variables and quotes
 */
t_rc	test_automata_exp_quotes(void *ctx)
{
	t_rc			rc = RC_OK;
	char			*str_res;
	t_minishell_ctx *mini_ctx = (t_minishell_ctx *) ctx;

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "\"$HOME\"");
	rc = assert_str(str_res, "\"/home/\"");
	free(str_res);

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "\'$HOME\'");
	rc = assert_str(str_res, "\'$HOME\'");
	free(str_res);

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "\'\"$HOME\"\'");
	rc = assert_str(str_res, "\'\"$HOME\"\'");
	free(str_res);

	str_res = automata_exp_evaluate(mini_ctx->automata_expander, mini_ctx->env, "\"\'$HOME\'\"");
	rc = assert_str(str_res, "\"\'/home/\'\"");
	free(str_res);

	return(rc);
}

void	test_automata_exp(void *envp)
{
	t_minishell_ctx	ctx;
	char	*mock_env[] = {
		"HOME=/home/",
		"USR=javier",
		"DOLLAR=$",
		"DOLLARUSR=$USR",
		NULL,
	};

	(void) envp;
	ctx.env = environment_create(mock_env);
	ft_printf("\n---------------------------------------------------\n");
	ft_printf("TEST AUTOMATA EXPANSER\n\n");

	print_test_res("test_automata_exp_init", test_automata_exp_init(&ctx));
	print_test_res("test_automata_exp_null_parses", test_automata_exp_null_parses(&ctx));
	print_test_res("test_automata_exp_empty_vars", test_automata_exp_empty_vars(&ctx));
	print_test_res("test_automata_exp_real_vars", test_automata_exp_real_vars(&ctx));
	print_test_res("test_automata_exp_quotes", test_automata_exp_quotes(&ctx));

	ft_lstclear(&ctx.env, environment_variable_free);
	automata_exp_free(ctx.automata_expander);
	ft_printf("---------------------------------------------------\n");
}
