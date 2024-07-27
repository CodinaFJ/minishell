/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_lexer_actions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:24:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/27 14:12:00 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_lexer.h"

void	get_token_command(t_automata_lexer *automata, void *ctx)
{
	char	*token;
	char	*str_aux;

	(void) ctx;
	str_aux = ft_substr(automata->str,
			automata->cursor_pre,
			automata->cursor - automata->cursor_pre);
	token = ft_strtrim(str_aux, " ");
	automata->cursor_pre = automata->cursor;
	tokenbt_insert_comm_word(ctx, token);
	free(token);
	free(str_aux);
}

void	get_token_oprtr(t_automata_lexer *automata, void *ctx)
{
	char	*token;
	char	*str_aux;

	(void) ctx;
	str_aux = ft_substr(automata->str,
			automata->cursor_pre,
			automata->cursor - automata->cursor_pre);
	token = ft_strtrim(str_aux, " ");
	automata->cursor_pre = automata->cursor;
	tokenbt_insert_oprtr(ctx, token);
	free(token);
	free(str_aux);
}

void	end_evaluation(t_automata_lexer *automata, void *ctx)
{
	if (automata->errors[automata->state] != NULL)
	{
		ft_printf("[ERROR] -> %s\n", automata->errors[automata->state]);
		return ;
	}
	get_token_command(automata, ctx);
}
