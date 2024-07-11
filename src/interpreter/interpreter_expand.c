/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_expand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:30:38 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/11 20:16:49 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static char	*expand_string(t_minishell_ctx *ctx, char *str)
{
    return (automata_exp_evaluate(ctx->automata_expander, ctx, str));
}

static void	interpreter_expand_btree(t_btree *btree, t_minishell_ctx *ctx)
{
	int			i;
	t_command	*command;

	i = -1;
	if (((t_token *)(btree->content))->id == COMMAND)
	{
		command = (t_command *) ((t_token_content*)((t_token *)(btree->content))->content);
		command->command = expand_string(ctx, command->command);
        ft_printf("command: %s\n", command->command);
		while (command->args[++i] != NULL)
        {
			command->args[i] = expand_string(ctx, command->args[i]);
            ft_printf("arg: %s\n", command->args[i]);
        } 
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
