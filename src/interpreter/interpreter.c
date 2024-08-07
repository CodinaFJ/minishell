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

static t_rc	split_to_token(int *i, int *prev_i, t_command *command)
{
	char	*str_aux;
	char	*str_aux2;

	str_aux = ft_substr(command->command, *prev_i, *i - *prev_i);
	if (str_aux == NULL)
		return (RC_NOK);
	str_aux2 = ft_strtrim(str_aux, " ");
	if (str_aux2 == NULL)
		return (RC_NOK);
	ft_strs_add_line(str_aux2, command->args);
	free(str_aux);
	free(str_aux2);
	*prev_i = *i;
	while (command->command[++(*i)] == ' ')
		;
	return (RC_OK);
}

static t_rc	split_parameters(t_token *token)
{
	t_command	*command;
	char		quote;
	int			prev_i;
	int			i;

	i = -1;
	prev_i = 0;
	command = (t_command *)token->content;
	while (command->command[++i])
	{
		if (command->command[i] == ' ')
		{
			if (split_to_token(&i, &prev_i, command) != RC_OK)
				return (RC_NOK);
		}
		else if (command->command[i] == '\'' || command->command[i] == '\"')
		{
			quote = command->command[i];
			while (command->command[++i] != quote)
				;
		}
	}
	return (split_to_token(&i, &prev_i, command) != RC_OK);
}

static t_rc	interpreter_structure_commands_params(t_btree *btree)
{
	t_token	*token;

	token = (t_token *)btree->content;
	if (token->id == COMMAND)
		if (split_parameters(token) == RC_NOK)
			return (RC_NOK);
	if (btree->left != NULL)
		if (interpreter_structure_commands_params(btree->left) == RC_NOK)
			return (RC_NOK);
	if (btree->right != NULL)
		if (interpreter_structure_commands_params(btree->right) == RC_NOK)
			return (RC_NOK);
	return (RC_OK);
}

static t_rc	interpreter_recognize_tokens(t_minishell_ctx *ctx)
{
	btree_clear(ctx->tokens_bt, token_free);
	automata_lexer_evaluate(ctx->automata_lexer, ctx->tokens_bt,
		ctx->input_str);
	return (RC_OK);
}

t_rc	interpreter_get_line(t_minishell_ctx *ctx)
{
	ctx->input_str = readline(SHELL_PROMT);
	if (ctx->input_str == NULL || !ft_strcmp(ctx->input_str, ""))
		return (RC_NOK);
	add_history(ctx->input_str);
	interpreter_recognize_tokens(ctx);
	interpreter_expand(ctx);
	interpreter_structure_commands_params(ctx->tokens_bt);
	// btree_print(ctx->tokens_bt, "0", token_print); MARINA: si quieres ver el arbol de comandos cada vez que metes uno descomenta esta linea.
	return (RC_OK);
}
