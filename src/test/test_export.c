/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:53:35 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/26 13:14:57by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static t_rc test_export_var(void *ctx)
{
	t_rc	rc = RC_OK;
	char	*var;
	t_minishell_ctx	*mini_ctx = (t_minishell_ctx *)ctx;
	
	builtin_export("FOO=bar", mini_ctx);
	var = environment_get(mini_ctx->env, "FOO");
	rc = assert_str(var, "bar") == RC_OK ? rc : RC_NOK;
	free(var);

	builtin_export("FOO=foo", mini_ctx);
	var = environment_get(mini_ctx->env, "FOO");
	rc = assert_str(var, "foo") == RC_OK ? rc : RC_NOK;
	free(var);

	environment_unset(&mini_ctx->env, "FOO");
	return (rc);
}

static t_rc test_export_empty_var(void *ctx)
{
	t_rc	rc = RC_OK;
	char	*var;
	t_minishell_ctx	*mini_ctx = (t_minishell_ctx *)ctx;
	
	builtin_export("FOO", mini_ctx);
	var = environment_get(mini_ctx->env, "FOO");
	rc = assert_str(var, NULL) == RC_OK ? rc : RC_NOK;

	builtin_export("FOO=", mini_ctx);
	var = environment_get(mini_ctx->env, "FOO");
	rc = assert_str(var, "") == RC_OK ? rc : RC_NOK;
	free(var);

	builtin_export("FOO=bar", mini_ctx);
	var = environment_get(mini_ctx->env, "FOO");
	rc = assert_str(var, "bar") == RC_OK ? rc : RC_NOK;
	free(var);

	builtin_export("FOO", mini_ctx);
	var = environment_get(mini_ctx->env, "FOO");
	rc = assert_str(var, "bar") == RC_OK ? rc : RC_NOK;
	free(var);

	builtin_export("FOO=", mini_ctx);
	var = environment_get(mini_ctx->env, "FOO");
	rc = assert_str(var, "") == RC_OK ? rc : RC_NOK;
	free(var);

	environment_unset(&mini_ctx->env, "FOO");
	return (rc);
}

static t_rc test_export_print(void *ctx)
{
	printf("\n");
	builtin_export(NULL, ctx);
	printf("\n");

	return (RC_OK);
}

void	test_export(void *envp)
{
	t_minishell_ctx	ctx;
	char	*mock_env[] = {
		"USR=javier",
		"DOLLAR=$",
		"B=/home/",
		"A=/home/",
		"DOLLARUSR=$USR",
		"HOME=/home/",
		NULL,
	};

	(void) envp;
	ft_bzero(&ctx, sizeof(t_minishell_ctx));
	ctx.env = environment_create(mock_env);
	printf("\n---------------------------------------------------\n");
	printf("TEST EXPORT\n\n");
	
	print_test_res("test_export_var", test_export_var(&ctx));
	print_test_res("test_export_empty_var", test_export_empty_var(&ctx));
	print_test_res("test_export_empty", test_export_print(&ctx));

	printf("---------------------------------------------------\n");
	environment_free(&ctx.env);
}