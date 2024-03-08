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

static void automata_evaluate_char(t_automata *automata, void *automata_ctx)
{
	automata->state = automata->get_state(automata->state, alphabet_index(automata->alphabet, automata->str[automata->cursor]));
	if (automata->state_enter_action[automata->state])
		automata->state_enter_action[automata->state](automata, automata_ctx);
	if (automata->state_trans_action[automata->prev_state][automata->state])
		automata->state_trans_action[automata->prev_state][automata->state](automata, automata_ctx);
	automata->prev_state = automata->state;
	automata->cursor++;
}

static void automata_evaluate_end(t_automata *automata, void *ctx)
{
	automata->end_eval_action(automata, ctx);
	if (automata->str != NULL)
	{
		free(automata->str);
		automata->str = NULL;
	}
}

int	automata_evaluate(t_automata *automata, void *automata_ctx, char *str)
{
	int	str_len;

	automata->str = ft_strdup(str);// !This dup is not protected, if malloc fails we have segfault
	str_len = (int) ft_strlen(automata->str);
	automata_evaluate_start(automata);
	while (automata->cursor < str_len)
		automata_evaluate_char(automata, automata_ctx);
	automata_evaluate_end(automata, automata_ctx);
	return (automata->state);
}
