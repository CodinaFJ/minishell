/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:19:35 by marubio-          #+#    #+#             */
/*   Updated: 2024/07/26 16:10:44 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void builtin_env(void *command, void *ctx) 
{
	t_list	*env;
	t_minishell_ctx	*mini_ctx;

	(void) command;
	mini_ctx = (t_minishell_ctx *) ctx;
	env = mini_ctx->env;
	while (env)
	{
		if (env == NULL)
			continue ;
		environment_variable_print(env->content);
		env = env->next;
	}
}
