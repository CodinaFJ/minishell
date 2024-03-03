/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_evaluate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:22:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/21 20:34:37 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata.h"

static int	alphabet_index(char **alphabet, char c)
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

static void	automata_evaluate_start(t_automata *automata)
{
	automata->prev_state = 0;
	automata->state = 0;
	automata->cursor = 0;
	automata->cursor_pre = 0;
}

static void automata_evaluate_char(t_automata *automata)
{
	automata->state = automata->get_state(automata->state, alphabet_index(automata->alphabet, automata->str[automata->cursor]));
	if (automata->state_enter_action[automata->state])
		automata->state_enter_action[automata->state](automata, automata->ctx);
	if (automata->state_trans_action[automata->prev_state][automata->state])
		automata->state_trans_action[automata->prev_state][automata->state](automata, automata->ctx);
	automata->prev_state = automata->state;
	automata->cursor++;
}

static void automata_evaluate_end(t_automata *automata)
{
	automata->end_eval_action(automata, automata->ctx);
	if (automata->str != NULL)
	{
		free(automata->str);
		automata->str = NULL;
	}
}

int	automata_evaluate(t_automata *automata, char *str)
{
	int	str_len;

	str_len = (int) ft_strlen(automata->str);
	automata_evaluate_start(automata);
	while (automata->cursor < str_len)
		automata_evaluate_char(automata);
	automata_evaluate_end(automata);
	return (automata->state);
}
