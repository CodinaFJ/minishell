/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:24:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 18:15:42 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata.h"

void	get_token_command(t_automata *automata, void *ctx)
{
	char			*token;

	(void) ctx;
	token = ft_strtrim(ft_substr(automata->str, automata->cursor_pre, automata->cursor - automata->cursor_pre), " ");
	automata->cursor_pre = automata->cursor;
	ft_printf("token comm -> %s\n", token);
	free (token);
}

void	get_token_oprtr(t_automata *automata, void *ctx)
{
	char			*token;

	(void) ctx;
	token = ft_strtrim(ft_substr(automata->str, automata->cursor_pre, automata->cursor - automata->cursor_pre), " ");
	automata->cursor_pre = automata->cursor;
	ft_printf("token oprtr -> %s\n", token);
	free (token);
}

void	end_evaluation(t_automata *automata, void *ctx)
{
	if (automata->errors[automata->state] != NULL)
	{
		ft_printf("[ERROR] -> %s\n", automata->errors[automata->state]);
		return ;
	}
	get_token_command(automata, ctx);
}
