/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:42:08 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/12 21:49:37 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


void	minishell_init(t_minishell_ctx *ctx, char **envp)
{
	ctx->env = environment_create(envp);
	ctx->builtins = builtins_init();
	if (ctx->env == NULL || ctx->builtins == NULL)
		return ;//ERROR
	signals_init();
	ctx->tokens_bt = btree_new(NULL);
	automatas_init(ctx);
}
