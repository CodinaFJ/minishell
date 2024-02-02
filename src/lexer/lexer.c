/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:20:23 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 20:01:47 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void	read_command(char *str, t_minishell_ctx *ctx)
{
	int			state;

	state = automata_evaluate(ctx->automata, str);	
	ft_printf("Automata ended in state: %d\n", state);
}

void	lexer_init(t_minishell_ctx *ctx)
{
	ctx->automata = automata_init(NULL);	
}
