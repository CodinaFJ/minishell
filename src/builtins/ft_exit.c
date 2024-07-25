/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:42:53 by marubio-          #+#    #+#             */
/*   Updated: 2024/07/25 22:08:59 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void ft_exit(void *command, void *ctx)
{
	t_minishell_ctx	*minish_ctx;

	minish_ctx = (t_minishell_ctx *) ctx;
	(void) command;
	(void) minish_ctx;
	//automata_free(minish_ctx->automata_lexer);
	//automata_free(minish_ctx->automata_expander);
	//btree_free(&(minish_ctx->tokens_bt), token_free);
	exit(0);
} 