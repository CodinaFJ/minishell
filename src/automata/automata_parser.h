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

typedef enum	e_automata_state
{
	EMPTY,
	WORD,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
	DOLLAR,
	TENT_TOKEN_END,
	TOKEN_END,
	ERROR
}	t_automata_state;

t_automata	*automata_init_parser(void *ctx);
int			automata_get_state(int i, int j);

#endif