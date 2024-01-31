/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:24:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/26 18:35:27 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata.h"

void	get_token(t_automata *automata, void *ctx)
{
	char			*token;

	(void) ctx;
	token = ft_substr(automata->str, automata->cursor_pre, automata->cursor - automata->cursor_pre);
	automata->cursor_pre = automata->cursor;
	ft_printf("token -> %s\n", token);
	free (token);
}