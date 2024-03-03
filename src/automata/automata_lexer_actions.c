/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:24:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/21 20:43:43 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata.h"

void	get_token_command(t_automata *automata, void *ctx)
{
	char			*token;

	(void) ctx;
	ft_printf("get_token_command\n");
	token = ft_strtrim(ft_substr(automata->str, automata->cursor_pre, automata->cursor - automata->cursor_pre), " ");// !This line leaks memory
	automata->cursor_pre = automata->cursor;
	tokenbt_insert_comm_word(automata->ctx, token);
	free(token);
}

void	get_token_oprtr(t_automata *automata, void *ctx)
{
	char			*token;

	(void) ctx;
	ft_printf("get_token_oprtr\n");
	token = ft_strtrim(ft_substr(automata->str, automata->cursor_pre, automata->cursor - automata->cursor_pre), " ");// !This line leaks memory
	automata->cursor_pre = automata->cursor;
	tokenbt_insert_oprtr(automata->ctx, token);
	free(token);
}

void	end_evaluation(t_automata *automata, void *ctx)
{
	if (automata->errors[automata->state] != NULL)
	{
		ft_printf("[ERROR] -> %s\n", automata->errors[automata->state]);
		return ;
	}
	get_token_command(automata, ctx);
	btree_print(automata->ctx, "0", token_print);
	btree_free((t_btree **) &(ctx), token_free);
}
