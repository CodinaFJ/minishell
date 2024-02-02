/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:51:07 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 18:14:55 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATA_H
# define AUTOMATA_H
# include "../../lib/libft/include/libft.h"
# define ALPHABET_LEN 7
# define AUTOMATA_STATES 14

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

int			automata_evaluate(t_automata *automata, char *str);
t_automata	*automata_init(void *ctx);
void		get_token_oprtr(t_automata *automata, void *ctx);
void		get_token_command(t_automata *automata, void *ctx);
int			automata_get_state(int i, int j);
void		end_evaluation(t_automata *automata, void *ctx);

void	minishell_actions_init(t_automata *automata);


#endif