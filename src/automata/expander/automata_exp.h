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
# include "../../../lib/data_structures_C/include/data_structures.h"
# include "../../minishell_ctx.h"
# include "../../environment/environment.h"
# include "../../minishell_exit/minishell_exit.h"
# include "../../lexer/token.h"

/* ************************************************************************** */
/*	Typedefs    															  */
/* ************************************************************************** */

typedef struct s_automata_exp
{
	void		*ctx;
	char		**alphabet;
	char		**errors;
	char		*str;
	int			prev_state;
	int			state;
	int			cursor;
	int			cursor_pre;
	int			str_len;
	void		(*state_enter_action[20])(struct s_automata_exp *a, void *ctx);
	void		(*state_trans_action[20][20])(struct s_automata_exp *a,
			void *ctx);
	void		(*end_eval_action)(struct s_automata_exp *a, void *ctx);
	int			(*get_state)(int state, int char_index);
}				t_automata_exp;

typedef enum e_automata_exp_state
{
	E_PRE_VAR,
	E_DOLLAR,
	E_SINGLE_CHAR_VAR,
	E_STRING_VAR,
	E_SIMPLE_QUOTE,
	E_DOUBLE_QUOTE,
	E_END
}				t_automata_exp_state;

/* ************************************************************************** */
/*	Functions    															  */
/* ************************************************************************** */

/*	Automata  																  */
char			*automata_exp_evaluate(t_automata_exp *automata, void *env,
					char *str);

t_automata_exp	*automata_exp_init(void);
int				automata_get_state(int i, int j);

void			end_exp_evaluation(t_automata_exp *automata, void *env);
void			abort_automata(t_automata_exp *automata, void *ctx);
void			minishell_actions_exp_init(t_automata_exp *automata);

void			remove_dollar(t_automata_exp *automata, void *ctx);
void			extract_variable(t_automata_exp *automata, void *ctx);
void			single_char_var(t_automata_exp *automata, void *ctx);

void			automata_exp_free(t_automata_exp *automata);
void			automata_exp_resume(t_automata_exp *automata, char *str_res);
int				strr_find_dollar(t_automata_exp *automata);
char			*ft_str_rmv_index(char *str, const unsigned int index);
char			*get_var_key(t_automata_exp *automata, int i);

#endif
