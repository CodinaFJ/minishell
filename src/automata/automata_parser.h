/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:18:33 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/21 21:02:15 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATA_PARSER_H
# define AUTOMATA_PARSER_H
# define ALPHABET_LEN 7
# define AUTOMATA_STATES 14

# include "automata.h"

typedef enum	e_automata_parser_state
{
	P_EMPTY,
	P_WORD,
	P_DOUBLE_QUOTES,
	P_SINGLE_QUOTES,
	P_DOLLAR,
	P_TENT_TOKEN_END,
	P_TOKEN_END,
	P_ERROR
}	t_automata_parser_state;

t_automata	*automata_init_parser(void);
int			automata_get_state(int i, int j);

#endif
