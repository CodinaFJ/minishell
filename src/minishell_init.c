/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:42:08 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/11 21:50:21 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	automatas_init(t_minishell_ctx *ctx)
{
	ctx->automata_lexer = automata_lexer_init();
	if (ctx->automata_lexer)
		minishell_exit_error(ctx, MALLOC_ERR);
	ctx->automata_expander = automata_exp_init();
	if (ctx->automata_expander)
		minishell_exit_error(ctx, MALLOC_ERR);
}

void	minishell_init(t_minishell_ctx *ctx, char **envp)
{
	ctx->env = environment_create(envp);
	ctx->builtins = builtins_init();
	if (ctx->env == NULL || ctx->builtins == NULL)
		minishell_exit_error(ctx, MALLOC_ERR);
	signals_init();
	ctx->tokens_bt = btree_new(NULL);
	if (ctx->tokens_bt)
		minishell_exit_error(ctx, MALLOC_ERR);
	automatas_init(ctx);
}
