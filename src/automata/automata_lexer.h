/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_lexer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:17:32 by jcodina-          #+#    #+#             */
/*   Updated: 08/03/2024 18:27:32 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATA_LEXER_H
# define AUTOMATA_LEXER_H
# define ALPHABET_LEN 7
# define AUTOMATA_STATES 14

# include "automata.h"

typedef enum	e_automata_state
{
	L_EMPTY,
	L_WORD,
	L_DOUBLE_QUOTES,
	L_SINGLE_QUOTES,
	L_PIPE,
	L_PIPE2,
	L_AMP,
	L_AMP2,
	L_LESS,
	L_LESS2,
	L_MORE,
	L_MORE2,
	L_TENT_TOKEN_END,
	L_TOKEN_END,
	L_ERROR
}	t_automata_state;

t_automata	*automata_lexer_init(void);
int			automata_get_state(int i, int j);
void		minishell_actions_lexer_init(t_automata *automata);
void		end_evaluation(t_automata *automata, void *ctx);
void		get_token_oprtr(t_automata *automata, void *ctx);
void		get_token_command(t_automata *automata, void *ctx);

#endif
