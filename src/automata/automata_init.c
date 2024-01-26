/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:11:02 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/26 18:04:02 by jcodina-         ###   ########.fr       */
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

void	automata_init(t_automata *automata, void *context)
{
	//ft_printf("Automata initialization\n");
	ft_bzero(automata, sizeof(t_automata));
	minishell_alphabet_init(automata);
	automata->get_state = minishell_get_state;
	automata->ctx = context;
}