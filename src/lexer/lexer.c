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
#include "libft/include/ft_printf.h"

char    *expand_string(t_minishell_ctx *ctx, char *str)
{
    return (automata_exp_evaluate(ctx->automata_expander, ctx, str));
}

void	expand_btree(t_btree *btree, t_minishell_ctx *ctx)
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
		expand_btree(btree->left, ctx);
	if (btree->right != NULL)
		expand_btree(btree->right, ctx);
}

void	read_command(char *str, t_minishell_ctx *ctx)
{
	int			state;

	(void) state;
	if (ctx->tokens_bt != NULL)
		btree_clear(ctx->tokens_bt, token_free);
	state = automata_lexer_evaluate(ctx->automata_lexer, ctx->tokens_bt, str);
	btree_print(ctx->tokens_bt, "0", token_print);
	ctx->automata_expander->ctx = ctx->tokens_bt;
	expand_btree(ctx->tokens_bt, ctx);
	// TODO: Error control if automata exits in error state
	//ft_printf("Automata ended in state: %d\n", state);
}

void	automatas_init(t_minishell_ctx *ctx)
{
	ctx->automata_lexer = automata_lexer_init();
	ctx->automata_expander = automata_exp_init();
}
