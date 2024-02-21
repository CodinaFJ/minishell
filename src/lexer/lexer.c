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


void	read_command(char *str, t_minishell_ctx *ctx)
{
	int			state;

	if (ctx->tokens_bt != NULL)
		btree_clear(ctx->tokens_bt, token_free);
	ctx->automata->ctx = ctx->tokens_bt;
	state = automata_evaluate(ctx->automata, str);
	ft_printf("Automata ended in state: %d\n", state);
}

void	lexer_init(t_minishell_ctx *ctx)
{
	ctx->automata = automata_lexer_init(NULL);	
}
