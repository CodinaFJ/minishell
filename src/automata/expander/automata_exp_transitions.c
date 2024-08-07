/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_transitions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:08:33 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/20 22:56:48 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	enter_dollar(t_automata_exp *automata, void *ctx)
{
	(void)automata;
	(void)ctx;
}

static void	enter_state_actions(t_automata_exp *automata)
{
	automata->state_enter_action[E_SINGLE_CHAR_VAR] = single_char_var;
	automata->state_enter_action[E_DOLLAR] = enter_dollar;
}

static void	trans_state_actions(t_automata_exp *automata)
{
	automata->state_trans_action[E_DOLLAR][E_SIMPLE_QUOTE] = remove_dollar;
	automata->state_trans_action[E_DOLLAR][E_DOUBLE_QUOTE] = remove_dollar;
	automata->state_trans_action[E_STRING_VAR][E_PRE_VAR] = extract_variable;
	automata->state_trans_action[E_STRING_VAR][E_DOLLAR] = extract_variable;
	automata->state_trans_action[E_STRING_VAR][E_SIMPLE_QUOTE]
		= extract_variable;
	automata->state_trans_action[E_STRING_VAR][E_DOUBLE_QUOTE]
		= extract_variable;
}

void	minishell_actions_exp_init(t_automata_exp *automata)
{
	enter_state_actions(automata);
	trans_state_actions(automata);
	automata->end_eval_action = end_exp_evaluation;
}
