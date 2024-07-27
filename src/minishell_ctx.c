/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_ctx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:30:54 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/27 11:31:42 by jcodina-         ###   ########.fr       */
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
	btree_print(ctx->tokens_bt, "0", token_print);
	btree_free(&ctx->tokens_bt, token_free);
	builtins_free(ctx->builtins);
}
