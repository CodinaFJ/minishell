/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_lexer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:17:32 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/13 22:54:56 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATA_LEXER_H
# define AUTOMATA_LEXER_H
# define ALPHABET_LEXER_LEN 7
# define AUTOMATA_LEXER_STATES 14

# include "../../../lib/libft/include/libft.h"
# include "../../lexer/token.h"

/* ************************************************************************** */
/*	Typedefs    															  */
/* ************************************************************************** */

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

t_automata_lexer	*automata_lexer_init(void);
int     			automata_get_state(int i, int j);
void        		minishell_actions_lexer_init(t_automata_lexer *automata);
void        		end_evaluation(t_automata_lexer *automata, void *ctx);
void        		get_token_oprtr(t_automata_lexer *automata, void *ctx);
void        		get_token_command(t_automata_lexer *automata, void *ctx);
int	                automata_lexer_evaluate(t_automata_lexer *automata, void *automata_ctx, char *str);
void                automata_lexer_free(t_automata_lexer *automata);

#endif
