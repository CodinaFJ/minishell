/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:42:08 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 10:00:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


void	minishell_init(t_minishell_ctx *ctx)
{
	ctx->builtins = builtins_init();
	signals_init();
	lexer_init(ctx);	
}
