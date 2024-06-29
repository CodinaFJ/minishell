/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:24:44 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/29 13:06:55 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static t_rc	interpreter_structure_commands_args(t_minishell_ctx *ctx)
{
	(void) ctx;
	return (RC_OK);
}

static t_rc	interpreter_recognize_tokens(t_minishell_ctx *ctx)
{
	btree_clear(ctx->tokens_bt, token_free);
	automata_lexer_evaluate(ctx->automata_lexer, ctx->tokens_bt, ctx->input_str);
	return (RC_OK);
}

t_rc	interpreter_get_input(t_minishell_ctx *ctx)
{
	ctx->input_str = readline(SHELL_PROMT);
	if (ctx->input_str == NULL || !ft_strcmp(ctx->input_str, ""))	
		return (RC_NOK);
	interpreter_recognize_tokens(ctx);
	btree_print(ctx->tokens_bt, "0", token_print);
	interpreter_expand(ctx);
	btree_print(ctx->tokens_bt, "0", token_print);
	interpreter_structure_commands_args(ctx);
	return (RC_OK);
}