/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_expand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:30:38 by jcodina-          #+#    #+#             */
/*   Updated: 2024/08/27 18:07:14 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static char	*expand_string(t_minishell_ctx *ctx, char *str)
{
    return (automata_exp_evaluate(ctx->automata_expander, ctx, str));
}

static void	interpreter_expand_btree(t_btree *btree, t_minishell_ctx *ctx)
{
	char		*str_aux;
	t_command	*command;

	if (((t_token *)(btree->content))->id == COMMAND)
	{
		command = (t_command *) ((t_token_content*)((t_token *)(btree->content))->content);
		str_aux = expand_string(ctx, command->command);
		free(command->command);
		command->command = str_aux;
	}
	if (btree->left != NULL)
		interpreter_expand_btree(btree->left, ctx);
	if (btree->right != NULL)
		interpreter_expand_btree(btree->right, ctx);
}

t_rc	interpreter_expand(t_minishell_ctx *ctx)
{
	ctx->automata_expander->ctx = ctx->tokens_bt;
	interpreter_expand_btree(ctx->tokens_bt, ctx);
	return (RC_OK);
}
