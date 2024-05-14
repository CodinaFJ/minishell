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

#include "automata_exp.h"

static void	enter_state_actions(t_automata *automata)
{
	automata->state_enter_action[E_END] = abort_automata;
}

void	minishell_actions_exp_init(t_automata *automata)
{
	enter_state_actions(automata);
	automata->end_eval_action = end_exp_evaluation;
}
