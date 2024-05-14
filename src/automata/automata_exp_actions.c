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

#include "automata_exp.h"

void	end_exp_evaluation(t_automata *automata, void *ctx)
{
	char	*new_str;
	char	*old_str;

	old_str = (char *) ctx;
	// FUNCTION TO SUBSTITUTE A STRING INSIDE OTHER STRING
	// ft_str_subst(char* original_str, char* string_to_find, char* string_to_insert);
	write(1, automata->str, automata->str_len);
	ft_printf("\n len: %d\n", automata->str_len);
	if (automata->errors != NULL && automata->errors[automata->state] != NULL)
	{
		ft_printf("[ERROR] -> %s\n", automata->errors[automata->state]);
		return ;
	}
}

void	abort_automata(t_automata *automata, void *ctx)
{
	(void) ctx;
	automata->str_len = automata->cursor;
}
