/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_actions_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:08:33 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 17:34:57 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata.h"

static void	trans_to_oprtr(t_automata *automata)
{
	automata->state_trans_action[TENT_TOKEN_END][PIPE] = get_token;
	automata->state_trans_action[TENT_TOKEN_END][PIPE2] = get_token;
	automata->state_trans_action[TENT_TOKEN_END][AMP] = get_token;
	automata->state_trans_action[TENT_TOKEN_END][AMP2] = get_token;
	automata->state_trans_action[TENT_TOKEN_END][LESS] = get_token;
	automata->state_trans_action[TENT_TOKEN_END][LESS2] = get_token;
	automata->state_trans_action[TENT_TOKEN_END][MORE] = get_token;
	automata->state_trans_action[TENT_TOKEN_END][MORE2] = get_token;
	automata->state_trans_action[WORD][PIPE] = get_token;
	automata->state_trans_action[WORD][PIPE2] = get_token;
	automata->state_trans_action[WORD][AMP] = get_token;
	automata->state_trans_action[WORD][AMP2] = get_token;
	automata->state_trans_action[WORD][LESS] = get_token;
	automata->state_trans_action[WORD][LESS2] = get_token;
	automata->state_trans_action[WORD][MORE] = get_token;
	automata->state_trans_action[WORD][MORE2] = get_token;
}

static void	trans_to_quotes(t_automata *automata)
{
	automata->state_trans_action[PIPE][DOUBLE_QUOTES] = get_token;
	automata->state_trans_action[PIPE2][DOUBLE_QUOTES] = get_token;
	automata->state_trans_action[AMP][DOUBLE_QUOTES] = get_token;
	automata->state_trans_action[AMP2][DOUBLE_QUOTES] = get_token;
	automata->state_trans_action[LESS][DOUBLE_QUOTES] = get_token;
	automata->state_trans_action[LESS2][DOUBLE_QUOTES] = get_token;
	automata->state_trans_action[MORE][DOUBLE_QUOTES] = get_token;
	automata->state_trans_action[MORE2][DOUBLE_QUOTES] = get_token;
	automata->state_trans_action[PIPE][SINGLE_QUOTES] = get_token;
	automata->state_trans_action[PIPE2][SINGLE_QUOTES] = get_token;
	automata->state_trans_action[AMP][SINGLE_QUOTES] = get_token;
	automata->state_trans_action[AMP2][SINGLE_QUOTES] = get_token;
	automata->state_trans_action[LESS][SINGLE_QUOTES] = get_token;
	automata->state_trans_action[LESS2][SINGLE_QUOTES] = get_token;
	automata->state_trans_action[MORE][SINGLE_QUOTES] = get_token;
	automata->state_trans_action[MORE2][SINGLE_QUOTES] = get_token;
}

static void	trans_to_word(t_automata *automata)
{
	automata->state_trans_action[PIPE][WORD] = get_token;
	automata->state_trans_action[PIPE2][WORD] = get_token;
	automata->state_trans_action[AMP][WORD] = get_token;
	automata->state_trans_action[AMP2][WORD] = get_token;
	automata->state_trans_action[LESS][WORD] = get_token;
	automata->state_trans_action[LESS2][WORD] = get_token;
	automata->state_trans_action[MORE][WORD] = get_token;
	automata->state_trans_action[MORE2][WORD] = get_token;
}

void	minishell_actions_init(t_automata *automata)
{
	trans_to_oprtr(automata);
	trans_to_quotes(automata);
	trans_to_word(automata);
	automata->state_enter_action[TOKEN_END] = get_token;
	automata->end_eval_action = end_evaluation;
}
