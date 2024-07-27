/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_evaluate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:22:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/27 13:50:51 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

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

static void	automata_evaluate_start(t_automata_exp *automata)
{
	automata->prev_state = 0;
	automata->state = 0;
	automata->cursor = 0;
	automata->cursor_pre = 0;
}

static void	automata_evaluate_char(t_automata_exp *automata, void *ctx)
{
	automata->state = automata->get_state
		(automata->state,
			alphabet_index(automata->alphabet,
				automata->str[automata->cursor]));
	if (automata->state_enter_action[automata->state])
		automata->state_enter_action[automata->state](automata, ctx);
	if (automata->state_trans_action[automata->prev_state][automata->state])
		automata->state_trans_action[automata->prev_state][automata->state]
		(automata, ctx);
	automata->prev_state = automata->state;
	automata->cursor++;
}

char	*automata_exp_evaluate(t_automata_exp *automata, void *ctx, char *str)
{
	automata->str = ft_strdup(str);
	if (automata->str == NULL)
		return (NULL);
	else if ((automata->str)[0] == '\0')
		return (automata->str);
	automata->str_len = (int)ft_strlen(automata->str);
	automata_evaluate_start(automata);
	while (automata->cursor < automata->str_len)
		automata_evaluate_char(automata, ctx);
	automata->end_eval_action(automata, ctx);
	return (automata->str);
}
