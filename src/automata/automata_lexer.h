/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_lexer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:17:32 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/21 20:45:29 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATA_LEXER_H
# define AUTOMATA_LEXER_H
# define ALPHABET_LEN 7
# define AUTOMATA_STATES 14

# include "automata.h"

typedef enum	e_automata_state
{
	EMPTY,
	WORD,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
	PIPE,
	PIPE2,
	AMP,
	AMP2,
	LESS,
	LESS2,
	MORE,
	MORE2,
	TENT_TOKEN_END,
	TOKEN_END,
	ERROR
}	t_automata_state;

t_automata	*automata_lexer_init(void *ctx);
int			automata_get_state(int i, int j);
void		minishell_actions_init(t_automata *automata);
void		end_evaluation(t_automata *automata, void *ctx);
void		get_token_oprtr(t_automata *automata, void *ctx);
void		get_token_command(t_automata *automata, void *ctx);

#endif