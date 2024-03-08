/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_lexer_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:11:02 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/21 20:49:56 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_lexer.h"

void	minishell_alphabet_lexer_init(t_automata *automata)
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

void	minishell_errors_lexer_init(t_automata	*automata)
{
	automata->errors = ft_calloc(AUTOMATA_STATES + 1, sizeof(char *));
	if (automata->errors == NULL)
		return ;
	automata->errors[L_EMPTY] = ft_strdup("Empty string");
	automata->errors[L_DOUBLE_QUOTES] = ft_strdup("Open operator [\"]");
	automata->errors[L_SINGLE_QUOTES] = ft_strdup("Open operator [\']");
	automata->errors[L_PIPE] = ft_strdup("Open operator [|]");
	automata->errors[L_PIPE2] = ft_strdup("Open operator [||]");
	automata->errors[L_AMP] = ft_strdup("Open operator [&]");
	automata->errors[L_AMP2] = ft_strdup("Open operator [&&]");
	automata->errors[L_LESS] = ft_strdup("Open operator [<]");
	automata->errors[L_LESS2] = ft_strdup("Open operator [<<]");
	automata->errors[L_MORE] = ft_strdup("Open operator [>]");
	automata->errors[L_MORE2] = ft_strdup("Open operator [>>]");
	automata->errors[L_ERROR] = ft_strdup("Invalid input");
}

int	automata_get_state(int i, int j)
{
	const int	state[][8] = {
	//	\S    '   "   |   &   <   >   *
		{ 0,  2,  3, 11,  2,  1,  1,  1}, // 0 Empty input
		{13,  2,  3,  4,  6,  8, 10,  1}, // 1 Word
		{ 2, 12,  2,  2,  2,  2,  2,  2}, // 2 Open single quote
		{ 3,  3, 12,  3,  3,  3,  3,  3}, // 3 Open double quote
		{13,  2,  3,  5, 14, 14, 14,  1}, // 4 | operator
		{13,  2,  3, 14, 14, 14, 14,  1}, // 5 || operator
		{13,  2,  3, 14,  7, 14, 14,  1}, // 6 & operator
		{13,  2,  3, 14, 14, 14, 14,  1}, // 7 && operator
		{13,  2,  3, 14, 14,  9, 14,  1}, // 8 < operator
		{13,  2,  3, 14, 14, 14, 14,  1}, // 9 << operator
		{13,  2,  3, 14, 14, 14, 11,  1}, // 10 > operator
		{13,  2,  3, 14, 14, 14, 14,  1}, // 11 >> operator
		{13,  2,  3,  4,  6,  8, 10,  1}, // 12 Tentative token end
		{13,  2,  3,  4,  6,  8, 10,  1}, // 13 Token end
		{14, 14, 14, 14, 14, 14, 14, 14}, // 14 Error
	};
	//ft_printf("From state %d move to %d\n", i, state[i][j]);
	return (state[i][j]);
}

t_automata	*automata_lexer_init(void)
{
	t_automata	*automata;
	
	//ft_printf("Automata initialization\n");
	automata = ft_calloc(1, sizeof(t_automata));
	if (automata == NULL)
		return (NULL);
	automata->cursor = 0;
	automata->cursor_pre = 0;
	automata->state = 0;
	minishell_alphabet_lexer_init(automata);
	minishell_actions_lexer_init(automata);
	minishell_errors_lexer_init(automata);
	automata->get_state = automata_get_state;
	return (automata);
}
