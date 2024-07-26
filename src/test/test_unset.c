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

static t_rc test_unset_var(void *ctx)
{
	t_rc	rc = RC_OK;
	char	*var;
	t_minishell_ctx	*mini_ctx = (t_minishell_ctx *)ctx;
	
	var = environment_get(mini_ctx->env, "USR");
	rc = assert_str(var, "javier") == RC_OK ? rc : RC_NOK;
	free(var);
	builtin_unset("USR", mini_ctx);
	var = environment_get(mini_ctx->env, "USR");
	rc = assert_str(var, NULL) == RC_OK ? rc : RC_NOK;

	return (rc);
}

void	test_unset(void *envp)
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
	ft_printf("\n---------------------------------------------------\n");
	ft_printf("TEST UNSET\n\n");
	
	print_test_res("test_unset_var", test_unset_var(&ctx));

	ft_printf("---------------------------------------------------\n");
	environment_free(&ctx.env);
}
