/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:18:33 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/21 21:02:15 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATA_EXP_H
# define AUTOMATA_EXP_H
# define ALPHABET_EXP_LEN 6
# define AUTOMATA_EXP_STATES 7

# include "automata.h"

typedef enum	e_automata_exp_state
{
	E_PRE_VAR,
	E_DOLLAR,
	E_SINGLE_CHAR_VAR,
	E_STRING_VAR,
	E_SIMPLE_QUOTE,
	E_DOUBLE_QUOTE,
	E_END
}	t_automata_exp_state;

t_automata	*automata_init_exp(void);
int			automata_get_state(int i, int j);

void		end_exp_evaluation(t_automata *automata, void *ctx);
void		abort_automata(t_automata *automata, void *ctx);
void		minishell_actions_exp_init(t_automata *automata);

void		remove_dollar(t_automata *automata, void *ctx);
void		extract_variable(t_automata *automata, void *ctx);
void		single_char_var(t_automata *automata, void *ctx);

#endif
