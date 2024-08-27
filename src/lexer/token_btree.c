/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_btree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:35:55 by jcodina-          #+#    #+#             */
/*   Updated: 2024/08/27 18:17:32 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	tokenbt_insert_comm_word(t_btree *token_bt, char *token_str)
{
	t_btree		*node;

	node = token_bt;
	if (node == NULL || token_str == NULL)
		return ;
	// printf("[Insert command] -> ");
	while (node->right != NULL)
		node = node->right;
	if (node->content == NULL)
	{
		// printf("This new token\n");
		node->content = token_new(COMMAND, command_new(token_str, N_ARGS));
	}
	else if (((t_token *)node->content)->id == COMMAND)
	{
		// printf("This append arg\n");
		token_append_arg((t_token *)node->content, token_str);
	}
	else if (((t_token *)node->content)->id == OPERATOR)
	{
		// printf("Right new node\n");
		node->right = btree_new(token_new(COMMAND, command_new(token_str, N_ARGS)));
	}
}

void	tokenbt_insert_oprtr(t_btree *token_bt, char *token_str)
{
	t_btree		*node;

	node = token_bt;
	if (node == NULL || token_str == NULL)
		return ;
	// printf("[Insert operator] -> ");
	while (node->right != NULL)
		node = node->right;
	if (node->content == NULL)
	{
		// printf("This new node\n");
		node->content = token_new(COMMAND, operator_new(token_str));
	}
	else if (((t_token *)node->content)->id == OPERATOR)
	{
		// printf("Right new node\n");
		node->right = btree_new(token_new(OPERATOR, operator_new(token_str)));
	}
	else if (((t_token *)node->content)->id == COMMAND)
	{
		// printf("Move command to left and replace\n");
		node->left = btree_new(node->content);
		node->content = token_new(OPERATOR, operator_new(token_str));
	}
}
