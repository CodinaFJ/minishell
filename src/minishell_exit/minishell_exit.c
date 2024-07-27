/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:26:02 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/27 11:24:30 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exit.h"

void	minishell_exit(struct s_minishell_ctx *ctx, int exit_code)
{
	minishell_ctx_free(ctx);
	exit(exit_code);
}

void	minishell_exit_error(struct s_minishell_ctx *ctx, t_error_code error_code)
{
	ft_printf("Error %d\n", error_code);
	minishell_exit(ctx, 1);
}