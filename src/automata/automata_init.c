/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:11:02 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 17:37:29 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata.h"

void	minishell_alphabet_init(t_automata *automata)
{
	automata->alphabet = ft_calloc(ALPHABET_LEN + 1, sizeof(char *));
	if (automata->alphabet == NULL)
		return ;
	automata->alphabet[0] = NULL;
	ft_strs_add_line(" ", automata->alphabet);
	ft_strs_add_line("\'", automata->alphabet);
	ft_strs_add_line("\"", automata->alphabet);
	ft_strs_add_line("|", automata->alphabet);
	ft_strs_add_line("&", automata->alphabet);
	ft_strs_add_line("<", automata->alphabet);
	ft_strs_add_line(">", automata->alphabet);
}

void	minishell_errors_init(t_automata	*automata)
{
	automata->errors = ft_calloc(AUTOMATA_STATES + 1, sizeof(char *));
	if (automata->errors == NULL)
		return ;
	automata->errors[EMPTY] = ft_strdup("Empty string");
	automata->errors[DOUBLE_QUOTES] = ft_strdup("Open operator [\"]");
	automata->errors[SINGLE_QUOTES] = ft_strdup("Open operator [\']");
	automata->errors[PIPE] = ft_strdup("Open operator [|]");
	automata->errors[PIPE2] = ft_strdup("Open operator [||]");
	automata->errors[AMP] = ft_strdup("Open operator [&]");
	automata->errors[AMP2] = ft_strdup("Open operator [&&]");
	automata->errors[LESS] = ft_strdup("Open operator [<]");
	automata->errors[LESS2] = ft_strdup("Open operator [<<]");
	automata->errors[MORE] = ft_strdup("Open operator [>]");
	automata->errors[MORE2] = ft_strdup("Open operator [>>]");
	automata->errors[ERROR] = ft_strdup("Invalid input");
}

t_automata	*automata_init(void *context)
{
	t_automata	*automata;
	
	//ft_printf("Automata initialization\n");
	automata = ft_calloc(1, sizeof(t_automata));
	if (automata == NULL)
		return (NULL);
	automata->cursor = 0;
	automata->cursor_pre = 0;
	automata->state = 0;
	minishell_alphabet_init(automata);
	minishell_actions_init(automata);
	minishell_errors_init(automata);
	automata->get_state = automata_get_state;
	automata->ctx = context;
	return (automata);
}
