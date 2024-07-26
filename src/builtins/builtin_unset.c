/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:43:05 by marubio-          #+#    #+#             */
/*   Updated: 2024/07/26 15:52:29 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_unset(void *command, void *ctx)
{
	t_minishell_ctx	*mini_ctx;
	
	mini_ctx = (t_minishell_ctx *) ctx;
	environment_unset(&mini_ctx->env, command);
}
