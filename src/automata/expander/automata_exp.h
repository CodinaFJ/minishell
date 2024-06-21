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
# include "../../../lib/libft/include/libft.h"
# include "../../lexer/token.h"
# include "../../environment/environment.h"

/* ************************************************************************** */
/*	Typedefs    															  */
/* ************************************************************************** */

typedef struct s_automata_exp
{
	void	*ctx;
	char	**alphabet;
	char	**errors;
	char	*str;
	int		prev_state;
	int		state;
	int		cursor;
	int		cursor_pre;
	int		str_len;
	void	(*state_enter_action[20])(struct s_automata_exp *a, void *env);
	void	(*state_trans_action[20][20])(struct s_automata_exp *a, void *env);
	void	(*end_eval_action)(struct s_automata_exp *a, void *env);
	int		(*get_state)(int state, int char_index);
}	t_automata_exp;

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

/* ************************************************************************** */
/*	Functions    															  */
/* ************************************************************************** */

/*	Automata  																  */
char            *automata_exp_evaluate(t_automata_exp* automata, void * env,
				char *str);

void        	automata_exp_free(t_automata_exp *automata);
t_automata_exp	*automata_exp_init(void);
int 			automata_get_state(int i, int j);

void            end_exp_evaluation(t_automata_exp *automata, void *env);
void    		abort_automata(t_automata_exp *automata, void *ctx);
void    		minishell_actions_exp_init(t_automata_exp *automata);

void    		remove_dollar(t_automata_exp *automata, void *ctx);
void    		extract_variable(t_automata_exp *automata, void *env);
void    		single_char_var(t_automata_exp *automata, void *ctx);


void            automata_exp_free(t_automata_exp *automata);

#endif
