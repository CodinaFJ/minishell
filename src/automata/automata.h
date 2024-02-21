/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:51:07 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/21 20:45:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATA_H
# define AUTOMATA_H
# include "../../lib/libft/include/libft.h"
# include "../lexer/token.h"

/* ************************************************************************** */
/*	Typedefs    															  */
/* ************************************************************************** */

typedef struct s_automata
{
	void	*ctx;
	char	**alphabet;
	char	**errors;
	char	*str;
	int		prev_state;
	int		state;
	int		cursor;
	int		cursor_pre;
	void	(*state_enter_action[20])(struct s_automata *a, void *ctx);
	void	(*state_trans_action[20][20])(struct s_automata *a, void *ctx);
	void	(*end_eval_action)(struct s_automata *a, void *ctx);
	int		(*get_state)(int state, int char_index);
}	t_automata;

/* ************************************************************************** */
/*	Functions    															  */
/* ************************************************************************** */

/*	Automata  																  */
int			automata_evaluate(t_automata *automata, char *str);


#endif