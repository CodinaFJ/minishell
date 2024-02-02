/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:22:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 17:38:57 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata.h"

static int	char_index(char **alphabet, char c)
{
	int	i;
	
	i = 0;
	while (alphabet[i] != NULL)
	{
		if (ft_strchr(alphabet[i], c) != NULL)
			break ;
		i++;
	}
	return (i);
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

int	automata_evaluate(t_automata *automata, char *str)
{
	int	str_len;

	automata->str = ft_strtrim(str, "\n");
	str_len = (int) ft_strlen(automata->str);
	automata->prev_state = EMPTY;
	automata->state = EMPTY;
	automata->cursor = 0;
	automata->cursor_pre = 0;
	while (automata->cursor < str_len)
	{
		automata->state = automata->get_state(automata->state, char_index(automata->alphabet, automata->str[automata->cursor]));
		if (automata->state_enter_action[automata->state])
			automata->state_enter_action[automata->state](automata, automata->ctx);
		if (automata->state_trans_action[automata->prev_state][automata->state])
			automata->state_trans_action[automata->prev_state][automata->state](automata, automata->ctx);
		automata->prev_state = automata->state;
		automata->cursor++;
	}
	automata->end_eval_action(automata, automata->ctx);
	free(automata->str);
	return (automata->state);
}
