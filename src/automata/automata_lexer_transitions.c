/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_actions_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:08:33 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/21 20:21:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_lexer.h"

static void	trans_to_oprtr(t_automata *automata)
{
	int	i;

	i = L_PIPE;
	while (i <= L_MORE2)
	{
		automata->state_trans_action[L_TENT_TOKEN_END][i] = get_token_command;
		automata->state_trans_action[L_WORD][i] = get_token_command;
		i++;
	}
}

static void	trans_from_oprtr(t_automata *automata)
{
	int	i;

	i = L_PIPE;
	while (i <= L_MORE2)
	{
		automata->state_trans_action[i][L_DOUBLE_QUOTES] = get_token_oprtr;
		automata->state_trans_action[i][L_SINGLE_QUOTES] = get_token_oprtr;
		automata->state_trans_action[i][L_WORD] = get_token_oprtr;
		automata->state_trans_action[i][L_TOKEN_END] = get_token_oprtr;
		i++;
	}
}

static void trans_to_token_end(t_automata *automata)
{
	automata->state_trans_action[L_WORD][L_TOKEN_END] = get_token_command;
	automata->state_trans_action[L_TENT_TOKEN_END][L_TOKEN_END] = get_token_command;
}

void	minishell_actions_lexer_init(t_automata *automata)
{
	trans_to_oprtr(automata);
	trans_from_oprtr(automata);
	trans_to_token_end(automata);
	automata->end_eval_action = end_evaluation;
}
