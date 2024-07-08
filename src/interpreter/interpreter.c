/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:24:44 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/06 22:59:18 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static t_rc	split_parameters(t_token *token)
{
	const t_command		*command = (t_command *) token->content;
	char				*str_aux;
	char				quote;
	unsigned int		prev_i;
	unsigned int		i;
	
	i = 0;
	prev_i = 0;
	str_aux = command->command;
	while (command->command[i])
	{
		if (command->command[i] == ' ')
		{
			ft_strs_add_line(ft_substr(str_aux, prev_i, i), command->args);
			prev_i = i + 1;
		}
		else if (command->command[i] == '\'' || command->command[i] == '\"')
		{
			quote = command->command[i];
			while (command->command[i] != quote)
				i++;
			i++;
			continue ;
		}
		i++;
	}
	ft_strs_add_line(ft_substr(str_aux, prev_i, i), command->args);
	return (RC_OK);
}

static t_rc	interpreter_structure_commands_params(t_btree *btree)
{
	t_token	*token;

	token = (t_token *)btree->content;
	if (token->id == COMMAND)
	{
		if(split_parameters(token) == RC_NOK)
			return (RC_NOK);
	}
	if (btree->left != NULL)
	{
		if(interpreter_structure_commands_params(btree->left) == RC_NOK)
			return (RC_NOK);
	}
	if (btree->right != NULL)
	{
		if(interpreter_structure_commands_params(btree->right) == RC_NOK)
			return (RC_NOK);
	}
	return (RC_OK);
}

static t_rc	interpreter_recognize_tokens(t_minishell_ctx *ctx)
{
	btree_clear(ctx->tokens_bt, token_free);
	automata_lexer_evaluate(ctx->automata_lexer, ctx->tokens_bt, ctx->input_str);
	return (RC_OK);
}

t_rc	interpreter_get_line(t_minishell_ctx *ctx)
{
	ctx->input_str = readline(SHELL_PROMT);
	if (ctx->input_str == NULL || !ft_strcmp(ctx->input_str, ""))	
		return (RC_NOK);
	add_history(ctx->input_str);
	interpreter_recognize_tokens(ctx);
	// btree_print(ctx->tokens_bt, "0", token_print);
	interpreter_expand(ctx);
	if (1)
	{
		interpreter_structure_commands_params(ctx->tokens_bt);
	}
	btree_print(ctx->tokens_bt, "0", token_print);
	return (RC_OK);
}
