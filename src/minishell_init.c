/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:42:08 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/29 12:48:06 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	automatas_init(t_minishell_ctx *ctx)
{
	ctx->automata_lexer = automata_lexer_init();
	ctx->automata_expander = automata_exp_init();
}

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
