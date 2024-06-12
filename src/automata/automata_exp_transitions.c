/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_transitions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:08:33 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/13 00:47:56 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_exp.h"

static void	enter_state_actions(t_automata *automata)
{
	automata->state_enter_action[E_SINGLE_CHAR_VAR] = single_char_var;
}

static void	trans_state_actions(t_automata *automata)
{
	automata->state_trans_action[E_DOLLAR][E_SIMPLE_QUOTE] = remove_dollar;
	automata->state_trans_action[E_DOLLAR][E_DOUBLE_QUOTE] = remove_dollar;
	automata->state_trans_action[E_STRING_VAR][E_PRE_VAR] = extract_variable;
	automata->state_trans_action[E_STRING_VAR][E_DOLLAR] = extract_variable; 
	automata->state_trans_action[E_STRING_VAR][E_SIMPLE_QUOTE] = extract_variable;
	automata->state_trans_action[E_STRING_VAR][E_DOUBLE_QUOTE] = extract_variable;
}

void	minishell_actions_exp_init(t_automata *automata)
{
	enter_state_actions(automata);
	automata->end_eval_action = end_exp_evaluation;
}
