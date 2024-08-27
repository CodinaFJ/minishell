/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:42:56 by marubio-          #+#    #+#             */
/*   Updated: 2024/07/25 22:12:39by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_export(t_minishell_ctx *ctx)
{
	t_list	*env;

	ctx->env = ft_lst_sort(ctx->env, &environment_variable_cmp);
	env = ctx->env;
	while (env)
	{
		if (env == NULL)
			continue ;
		printf("declare -x ");
		environment_variable_print(env->content);
		env = env->next;
	}
}

void builtin_export(void *command, void *ctx)
{
	t_minishell_ctx *minishell_ctx;

	minishell_ctx = (t_minishell_ctx *) ctx;
	if (command == NULL)
		print_export(ctx);
	environment_set_str(minishell_ctx->env, (char *) command);
}
