/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:42:56 by marubio-          #+#    #+#             */
/*   Updated: 2024/07/25 22:12:39by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void ft_export(void *command, void *ctx)
{
	t_env_var	*env_var;
	t_minishell_ctx *minishell_ctx;

	minishell_ctx = (t_minishell_ctx *) ctx;
	env_var = environment_variable_parse(command);
	if (env_var == NULL)
		return ;
	environment_set(minishell_ctx->env, env_var->key, env_var->content);
}
