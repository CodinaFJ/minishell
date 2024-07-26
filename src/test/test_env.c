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

static t_rc test_builtin_env(void *ctx)
{
	ft_printf("\n");
	builtin_env(NULL, ctx);
	ft_printf("\n");

	return (RC_OK);
}

void	test_env(void *envp)
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
	ft_printf("TEST BUILTIN ENV\n\n");
	
	print_test_res("test_builtin_env", test_builtin_env(&ctx));

	ft_printf("---------------------------------------------------\n");
	environment_free(&ctx.env);
}
