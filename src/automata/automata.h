/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:51:07 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/26 17:15:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATA_H
# define AUTOMATA_H
# include "../../lib/libft/include/libft.h"
# define ALPHABET_LEN 7

typedef enum	e_automata_state
{
	EMPTY,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
	INVALID,
	SEPARATION,
	CHARACTER
}	t_automata_state;

typedef struct s_automata
{
	void	*ctx;
	char	**alphabet;
	char	**errors;
	char	*str;
	int		prev_state;
	int		state;
	int		cursor;
	void	(*state_enter_action[20])(struct s_automata *a, void *ctx);
	void	(*state_trans_action[20][20])(struct s_automata *a, void *ctx);
	int		(*get_state)(int state, int char_index);
}	t_automata;

int		automata_evaluate(t_automata *automata, char *str);
void	automata_init(t_automata *automata, void *ctx);

#endif