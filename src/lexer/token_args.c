/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:07:04 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 13:09:30 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	token_append_arg(t_token *token, char *arg)
{
	if (token->id == COMMAND)
		command_append_arg((t_command *) token->content, arg);
}
