/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_lexer_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:11:02 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/27 14:03:55 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_lexer.h"

void	minishell_alphabet_lexer_init(t_automata_lexer *automata)
{
	automata->alphabet = ft_calloc(ALPHABET_LEXER_LEN + 1, sizeof(char *));
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

void	minishell_errors_lexer_init(t_automata_lexer	*automata)
{
	automata->errors = ft_calloc(AUTOMATA_LEXER_STATES + 1, sizeof(char *));
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
	{0, 2, 3, 11, 2, 1, 1, 1},
	{1, 2, 3, 4, 6, 8, 10, 1},
	{2, 12, 2, 2, 2, 2, 2, 2},
	{3, 3, 12, 3, 3, 3, 3, 3},
	{1, 2, 3, 5, 14, 14, 14, 1},
	{1, 2, 3, 14, 14, 14, 14, 1},
	{1, 2, 3, 14, 7, 14, 14, 1},
	{1, 2, 3, 14, 14, 14, 14, 1},
	{1, 2, 3, 14, 14, 9, 14, 1},
	{1, 2, 3, 14, 14, 14, 14, 1},
	{1, 2, 3, 14, 14, 14, 11, 1},
	{1, 2, 3, 14, 14, 14, 14, 1},
	{1, 2, 3, 4, 6, 8, 10, 1},
	{13, 2, 3, 4, 6, 8, 10, 1},
	{14, 14, 14, 14, 14, 14, 14, 14},
	};

	return (state[i][j]);
}

t_automata_lexer	*automata_lexer_init(void)
{
	t_automata_lexer	*automata;

	automata = ft_calloc(1, sizeof(t_automata_lexer));
	if (automata == NULL)
		return (NULL);
	automata->cursor = 0;
	automata->cursor_pre = 0;
	automata->state = -1;
	automata->str_len = 0;
	minishell_alphabet_lexer_init(automata);
	minishell_actions_lexer_init(automata);
	minishell_errors_lexer_init(automata);
	automata->get_state = automata_get_state;
	return (automata);
}
