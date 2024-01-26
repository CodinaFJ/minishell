/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:22:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/26 17:41:07 by jcodina-         ###   ########.fr       */
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

int	automata_evaluate(t_automata *automata, char *str)
{
	int	str_len;

	automata->str = ft_strtrim(str, "\n");
	str_len = (int) ft_strlen(automata->str);
	automata->prev_state = EMPTY;
	automata->cursor = 0;
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
	free(automata->str);
	return (automata->state);
}
