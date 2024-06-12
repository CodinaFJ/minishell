/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:24:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/13 00:47:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_exp.h"

// char	*expand_var_len(char *str, int var_len)
// {

// }

void	end_exp_evaluation(t_automata *automata, void *ctx)
{
	//char	*new_str;
	//char	*old_str;

	(void) ctx;
	//old_str = (char *) ctx;
	// FUNCTION TO SUBSTITUTE A STRING INSIDE OTHER STRING
	// ft_str_subst(char* original_str, char* string_to_find, char* string_to_insert);
	write(1, automata->str, automata->str_len);
	ft_printf("\n");
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
void		remove_dollar()
{
	// Just remove the dollar that looks like is going to init a var but
	// is just useless. Ex:
	// echo $"hola"
	// echo $'hola'
}
void		extract_variable()
{
	// Extract variable retroactively, search reverse the dollar and look for
	// the variable
}

void		single_char_var()
{
	// Extract one char variable retroactively, search reverse the dollar and 
	// look for the variable. Here are special cases like $$ or $?, and
	// also $[number] -> this case should just be trated as a variable that
	// is not found.
	// Maybe this whole function could be done in the extract variable function
}
