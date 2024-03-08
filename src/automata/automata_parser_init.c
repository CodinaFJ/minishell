/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_parser_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:11:02 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/21 20:49:09 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_parser.h"

void	minishell_alphabet_parser_init(t_automata *automata)
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

void	minishell_errors_parser_init(t_automata	*automata)
{
	automata->errors = ft_calloc(AUTOMATA_STATES + 1, sizeof(char *));
	if (automata->errors == NULL)
		return ;
	automata->errors[P_EMPTY] = ft_strdup("Empty string");
	automata->errors[P_DOUBLE_QUOTES] = ft_strdup("Open operator [\"]");
	automata->errors[P_SINGLE_QUOTES] = ft_strdup("Open operator [\']");
	automata->errors[P_ERROR] = ft_strdup("Invalid input");
}

t_automata	*automata_init_parser(void)
{
	t_automata	*automata;
	
	//ft_printf("Automata initialization\n");
	automata = ft_calloc(1, sizeof(t_automata));
	if (automata == NULL)
		return (NULL);
	automata->cursor = 0;
	automata->cursor_pre = 0;
	automata->state = 0;
	minishell_alphabet_parser_init(automata);
	//minishell_actions_init(automata);
	minishell_errors_parser_init(automata);
	automata->get_state = automata_get_state;
	return (automata);
}
