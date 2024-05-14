/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:20:23 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/21 20:38:25 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	expand_string(t_automata *automata_expander, void *ctx, char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\'')
		{
			while (str[i] != '\'')
				i++;
		}
		if (str[i] == '$')
		{
			automata_evaluate(automata_expander, ctx, str + i + 1);
		}
	}
}

void	expand_btree(t_automata *automata_expander, t_btree *btree)
{
	int			i;
	t_command	*command;

	i = -1;
	if (((t_token *)(btree->content))->id == COMMAND)
	{
		command = (t_command *) ((t_token_content*)((t_token *)(btree->content))->content);
		expand_string(automata_expander, command->command, command->command);
		while (command->args[++i] != NULL)
			expand_string(automata_expander, command->command, command->args[i]);
	}
	if (btree->left != NULL)
		expand_btree(automata_expander, btree->left);
	if (btree->right != NULL)
		expand_btree(automata_expander, btree->right);
}

void	read_command(char *str, t_minishell_ctx *ctx)
{
	int			state;

	if (ctx->tokens_bt != NULL)
		btree_clear(ctx->tokens_bt, token_free);
	state = automata_evaluate(ctx->automata_lexer, ctx->tokens_bt, str);
	btree_print(ctx->tokens_bt, "0", token_print);
	ctx->automata_expander->ctx = ctx->tokens_bt;
	expand_btree(ctx->automata_expander, ctx->tokens_bt);
	// TODO: Error control if automata exits in error state
	//ft_printf("Automata ended in state: %d\n", state);
}

void	automatas_init(t_minishell_ctx *ctx)
{
	ctx->automata_lexer = automata_lexer_init();
	ctx->automata_expander = automata_init_exp();
}
