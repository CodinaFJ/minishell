/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:26:15 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/11 21:45:49 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "../minishell_ctx.h"

typedef enum  e_error_code
{
	MALLOC_ERR,
	OTHER_ERR
}	t_error_code;

void	minishell_exit(t_minishell_ctx *ctx, int exit_code);
void	minishell_exit_error(t_minishell_ctx *ctx, t_error_code error_code);

#endif