/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:14:42 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/13 22:19:21 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPES_H
# define MINISHELL_TYPES_H
# include "../lib/libft/include/libft.h"
# include "../lib/data_structures_C/include/data_structures.h"
# include "../src/builtins/builtin.h"
# include "../src/signals/signals.h"
# include "../src/environment/environment.h"

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
	void	(*state_enter_action[20])(struct s_automata_exp *a, void *ctx);
	void	(*state_trans_action[20][20])(struct s_automata_exp *a, void *ctx);
	char	*(*end_eval_action)(struct s_automata_exp *a, void *ctx);
	int		(*get_state)(int state, int char_index);
}	t_automata_exp;

typedef struct s_automata_lexer
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
	void	(*state_enter_action[20])(struct s_automata_lexer *a, void *ctx);
	void	(*state_trans_action[20][20])(struct s_automata_lexer *a, void *ctx);
	void	(*end_eval_action)(struct s_automata_lexer *a, void *ctx);
	int		(*get_state)(int state, int char_index);
}	t_automata_lexer;

typedef struct s_builtin
{
	char	*name;
	void	(*f)(void *ctx);
}	t_builtin;

typedef struct s_minishell_ctx
{
	t_automata_lexer	*automata_lexer;
	t_automata_exp  	*automata_expander;
	t_builtin         	**builtins;
	t_btree     		*tokens_bt;
	t_list      		*env;
}	t_minishell_ctx;

#endif