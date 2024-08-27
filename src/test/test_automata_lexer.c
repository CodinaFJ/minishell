/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_automata_lexer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:11:57 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/06 22:26:40y jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/**
 * test_automata_lexer_init
 * 
 * test initialization of automata
 * lexer
 */
t_rc	test_automata_lexer_init(void *ctx)
{
	t_rc	rc = RC_OK;
	t_automata_lexer	*automata;

	(void)ctx;
	automata = automata_lexer_init();
	rc = assert(automata != NULL) == RC_OK ? rc : RC_NOK;
	rc = assert(automata->alphabet != NULL) == RC_OK ? rc : RC_NOK;
	rc = assert(ft_strs_rows((const char **) automata->alphabet) != 0) == RC_OK ? rc : RC_NOK;
	rc = assert(automata->errors != NULL) == RC_OK ? rc : RC_NOK;
	automata_lexer_free(automata);
	return(rc);
}

t_rc	test_automata_lexer_single_command(void *ctx)
{
	t_rc				rc = RC_OK;
	t_automata_lexer	*automata;
	char				*str = "foo bar diz nuts";
	t_token				*token;
	t_command			*command;

	(void)ctx;
	automata = automata_lexer_init();
	automata_lexer_evaluate(automata, ctx, str);
	token = (t_token *)((t_btree *) ctx)->content;
	command = (t_command *) token->content;
	rc = assert_str(command->command, str) == RC_OK ? rc : RC_NOK;
	btree_clear(ctx, token_free);
	automata_lexer_free(automata);
	return (rc);
}

t_rc	test_automata_lexer_single_command_dquotes(void *ctx)
{
	t_rc				rc = RC_OK;
	t_automata_lexer	*automata;
	char				*str = "foo bar \"diz nuts\"";
	t_token				*token;
	t_command			*command;

	(void)ctx;
	automata = automata_lexer_init();
	automata_lexer_evaluate(automata, ctx, str);
	token = (t_token *)((t_btree *) ctx)->content;
	command = (t_command *) token->content;
	rc = assert(token->id == COMMAND) == RC_OK ? rc : RC_NOK;
	rc = assert_str(command->command, str) == RC_OK ? rc : RC_NOK;
	btree_clear(ctx, token_free);
	automata_lexer_free(automata);
	return (rc);
}

t_rc	test_automata_lexer_single_command_squotes(void *ctx)
{
	t_rc				rc = RC_OK;
	t_automata_lexer	*automata;
	char				*str = "foo bar \'diz nuts\'";
	t_token				*token;
	t_command			*command;

	(void)ctx;
	automata = automata_lexer_init();
	automata_lexer_evaluate(automata, ctx, str);
	token = (t_token *)((t_btree *) ctx)->content;
	command = (t_command *) token->content;
	rc = assert(token->id == COMMAND) == RC_OK ? rc : RC_NOK;
	rc = assert_str(command->command, str) == RC_OK ? rc : RC_NOK;
	btree_clear(ctx, token_free);
	automata_lexer_free(automata);
	return (rc);
}

t_rc	test_automata_lexer_multiple_command(void *ctx)
{
	t_rc				rc = RC_OK;
	t_automata_lexer	*automata;
	char				*str = "foo bar || diz nuts >> toca mela";
	t_token				*token;
	t_command			*command;
	t_operator			*operator;

	(void)ctx;
	automata = automata_lexer_init();
	automata_lexer_evaluate(automata, ctx, str);

	token = (t_token *)((t_btree *) ctx)->content;
	operator = (t_operator *) token->content;
	rc = assert(token->id == OPERATOR) == RC_OK ? rc : RC_NOK;
	rc = assert_str(operator->op, "||") == RC_OK ? rc : RC_NOK;

	token = (t_token *)((t_btree *) ctx)->left->content;
	command = (t_command *) token->content;
	rc = assert(token->id == COMMAND) == RC_OK ? rc : RC_NOK;
	rc = assert_str(command->command, "foo bar") == RC_OK ? rc : RC_NOK;

	token = (t_token *)((t_btree *) ctx)->right->content;
	operator = (t_operator *) token->content;
	rc = assert(token->id == OPERATOR) == RC_OK ? rc : RC_NOK;
	rc = assert_str(operator->op, ">>") == RC_OK ? rc : RC_NOK;

	token = (t_token *)((t_btree *) ctx)->right->left->content;
	command = (t_command *) token->content;
	rc = assert(token->id == COMMAND) == RC_OK ? rc : RC_NOK;
	rc = assert_str(command->command, "diz nuts") == RC_OK ? rc : RC_NOK;

	token = (t_token *)((t_btree *) ctx)->right->right->content;
	command = (t_command *) token->content;
	rc = assert(token->id == COMMAND) == RC_OK ? rc : RC_NOK;
	rc = assert_str(command->command, "toca mela") == RC_OK ? rc : RC_NOK;

	btree_clear(ctx, token_free);
	automata_lexer_free(automata);
	return (rc);
}

t_rc	test_automata_lexer_multiple_command_dquotes(void *ctx)
{
	t_rc				rc = RC_OK;
	t_automata_lexer	*automata;
	char				*str = "foo bar || diz \"nuts >> toca mela\"";
	t_token				*token;
	t_command			*command;
	t_operator			*operator;

	(void)ctx;
	automata = automata_lexer_init();
	automata_lexer_evaluate(automata, ctx, str);

	token = (t_token *)((t_btree *) ctx)->content;
	operator = (t_operator *) token->content;
	rc = assert(token->id == OPERATOR) == RC_OK ? rc : RC_NOK;
	rc = assert_str(operator->op, "||") == RC_OK ? rc : RC_NOK;

	token = (t_token *)((t_btree *) ctx)->left->content;
	command = (t_command *) token->content;
	rc = assert(token->id == COMMAND) == RC_OK ? rc : RC_NOK;
	rc = assert_str(command->command, "foo bar") == RC_OK ? rc : RC_NOK;

	token = (t_token *)((t_btree *) ctx)->right->content;
	command = (t_command *) token->content;
	rc = assert(token->id == COMMAND) == RC_OK ? rc : RC_NOK;
	rc = assert_str(command->command, "diz \"nuts >> toca mela\"") == RC_OK ? rc : RC_NOK;

	btree_clear(ctx, token_free);
	automata_lexer_free(automata);
	return (rc);
}

t_rc	test_automata_lexer_multiple_command_squotes(void *ctx)
{
	t_rc				rc = RC_OK;
	t_automata_lexer	*automata;
	char				*str = "foo bar || diz \'nuts >> toca mela\'";
	t_token				*token;
	t_command			*command;
	t_operator			*operator;

	(void)ctx;
	automata = automata_lexer_init();
	automata_lexer_evaluate(automata, ctx, str);

	token = (t_token *)((t_btree *) ctx)->content;
	operator = (t_operator *) token->content;
	rc = assert(token->id == OPERATOR) == RC_OK ? rc : RC_NOK;
	rc = assert_str(operator->op, "||") == RC_OK ? rc : RC_NOK;

	token = (t_token *)((t_btree *) ctx)->left->content;
	command = (t_command *) token->content;
	rc = assert(token->id == COMMAND) == RC_OK ? rc : RC_NOK;
	rc = assert_str(command->command, "foo bar") == RC_OK ? rc : RC_NOK;

	token = (t_token *)((t_btree *) ctx)->right->content;
	command = (t_command *) token->content;
	rc = assert(token->id == COMMAND) == RC_OK ? rc : RC_NOK;
	rc = assert_str(command->command, "diz \'nuts >> toca mela\'") == RC_OK ? rc : RC_NOK;

	btree_clear(ctx, token_free);
	automata_lexer_free(automata);
	return (rc);
}

void	test_automata_lexer(void *ctx)
{
	t_btree	*btree = btree_new(NULL);

	ctx = btree;

	printf("\n---------------------------------------------------\n");
	printf("TEST AUTOMATA LEXER\n\n");

	print_test_res("automata_lexer_init", test_automata_lexer_init(ctx));
	print_test_res("test_automata_lexer_single_command", test_automata_lexer_single_command(ctx));
	print_test_res("test_automata_lexer_single_command_dquotes", test_automata_lexer_single_command_dquotes(ctx));
	print_test_res("test_automata_lexer_single_command_squotes", test_automata_lexer_single_command_squotes(ctx));
	print_test_res("test_automata_lexer_multiple_command", test_automata_lexer_multiple_command(ctx));
	print_test_res("test_automata_lexer_multiple_command_dquotes", test_automata_lexer_multiple_command_dquotes(ctx));
	print_test_res("test_automata_lexer_multiple_command_squotes", test_automata_lexer_multiple_command_squotes(ctx));

	btree_free(&btree, token_free);
	printf("---------------------------------------------------\n");
}
