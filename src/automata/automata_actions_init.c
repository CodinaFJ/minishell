/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_actions_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:08:33 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 18:23:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata.h"

static void	trans_to_oprtr(t_automata *automata)
{
	int	i;

	i = PIPE;
	while (i <= MORE2)
	{
		automata->state_trans_action[TENT_TOKEN_END][i] = get_token_command;
		automata->state_trans_action[WORD][i] = get_token_command;
		i++;
	}
}

static void	trans_from_oprtr(t_automata *automata)
{
	int	i;

	i = PIPE;
	while (i <= MORE2)
	{
		automata->state_trans_action[i][DOUBLE_QUOTES] = get_token_oprtr;
		automata->state_trans_action[i][SINGLE_QUOTES] = get_token_oprtr;
		automata->state_trans_action[i][WORD] = get_token_oprtr;
		automata->state_trans_action[i][TOKEN_END] = get_token_oprtr;
		i++;
	}
}

static void trans_to_token_end(t_automata *automata)
{
	automata->state_trans_action[WORD][TOKEN_END] = get_token_command;
	automata->state_trans_action[TENT_TOKEN_END][TOKEN_END] = get_token_command;
}

void	minishell_actions_init(t_automata *automata)
{
	trans_to_oprtr(automata);
	trans_from_oprtr(automata);
	trans_to_token_end(automata);
	automata->end_eval_action = end_evaluation;
}
