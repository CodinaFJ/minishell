/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_ctx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:30:54 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/20 23:05:35 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell_ctx_free(t_minishell_ctx *ctx)
{
	if (ctx == NULL)
		return ;
	automata_exp_free(ctx->automata_expander);
	automata_lexer_free(ctx->automata_lexer);
	environment_free(&(ctx->env));
	if (ctx->input_str)
		free(ctx->input_str);
	btree_free(&(ctx->tokens_bt), token_free);
	builtins_free(ctx->builtins);
}
