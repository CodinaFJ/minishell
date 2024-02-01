/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:11:02 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/01 21:34:25 by jcodina-         ###   ########.fr       */
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
	ft_strs_add_line("|", automata->alphabet);
	ft_strs_add_line("<", automata->alphabet);
	ft_strs_add_line(">", automata->alphabet);
	ft_strs_add_line("&", automata->alphabet);
	ft_strs_add_line("\'", automata->alphabet);
	ft_strs_add_line("\"", automata->alphabet);
}

int	minishell_get_state(int i, int j)
{
	const int	state[][8] = {
	//	\S    |   <   >   &   '   "   *
		{ 0,  3,  7,  8,  5,  2,  1, 13}, // 0 Empty input
		{ 1,  1,  1,  1,  1,  1, 12,  1}, // 1 Open double quote
		{ 2,  2,  2,  2,  2, 12,  2,  2}, // 2 Open single quote
		{12,  4,  7, 11, 11,  2,  1, 13}, // 3 Pipe open
		{12, 11, 11, 11, 11,  2,  1, 13}, // 4 OR open
		{12, 11, 11, 11,  6,  2,  1, 11}, // 5 & found
		{12, 11, 11, 11, 11,  2,  1, 13}, // 6 AND open
		{12, 11,  9, 11, 11,  2,  1, 13}, // 7 Less than open
		{12, 11, 11, 10, 11,  2,  1, 13}, // 8 More than open
		{12, 11, 11, 11, 11,  2,  1, 13}, // 9 Heredoc open
		{12, 11, 11, 11, 11,  2,  1, 13}, // 10 Append found
		{11, 11, 11, 11, 11, 11, 11, 11}, // 11 Invalid
		{12,  3,  7,  8,  5,  2,  1, 13}, // 12 Separation
		{12,  3,  7,  8,  5,  2,  1, 13}, // 13 Normal input (not operator)
	};
	//ft_printf("From state i(%d) receive j(%d) -> %d\n", i, j, state[i][j]);
	return (state[i][j]);
}

void	minishell_state_trans_init(t_automata *automata)
{
	automata->state_trans_action[CHARACTER][PIPE] = get_token;
	automata->state_trans_action[CHARACTER][LESS] = get_token;
	automata->state_trans_action[CHARACTER][GREATER] = get_token;
	automata->state_trans_action[CHARACTER][AMPERSAND] = get_token;
	automata->state_trans_action[SEPARATION][PIPE] = get_token;
	automata->state_trans_action[SEPARATION][LESS] = get_token;
	automata->state_trans_action[SEPARATION][GREATER] = get_token;
	automata->state_trans_action[SEPARATION][AMPERSAND] = get_token;
	automata->state_trans_action[PIPE][SEPARATION] = get_token;
	automata->state_trans_action[OR][SEPARATION] = get_token;
	automata->state_trans_action[AND][SEPARATION] = get_token;
	automata->state_trans_action[LESS][SEPARATION] = get_token;
	automata->state_trans_action[HEREDOC][SEPARATION] = get_token;
	automata->state_trans_action[GREATER][SEPARATION] = get_token;
	automata->state_trans_action[APPEND][SEPARATION] = get_token;
	automata->state_trans_action[PIPE][CHARACTER] = get_token;
	automata->state_trans_action[OR][CHARACTER] = get_token;
	automata->state_trans_action[AND][CHARACTER] = get_token;
	automata->state_trans_action[LESS][CHARACTER] = get_token;
	automata->state_trans_action[HEREDOC][CHARACTER] = get_token;
	automata->state_trans_action[GREATER][CHARACTER] = get_token;
	automata->state_trans_action[APPEND][CHARACTER] = get_token;
}

t_automata	*automata_init(void *context)
{
	t_automata	*automata;
	
	//ft_printf("Automata initialization\n");
	automata = ft_calloc(1, sizeof(t_automata));
	if (automata == NULL)
		return (NULL);
	minishell_alphabet_init(automata);
	minishell_state_trans_init(automata);
	automata->end_eval_action = get_token;
	automata->get_state = minishell_get_state;
	automata->ctx = context;
	return (automata);
}
