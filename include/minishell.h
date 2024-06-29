/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:16:43 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/29 12:47:35 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft/include/libft.h"
# include "../lib/data_structures_C/include/data_structures.h"
# include "../src/automata/expander/automata_exp.h"
# include "../src/automata/lexer/automata_lexer.h"
# include "../src/builtins/builtin.h"
# include "../src/signals/signals.h"
# include "../src/environment/environment.h"
# define SHELL_PROMT "\033[32;1mBashCrandicoot> \033[0;39m"


/* ************************************************************************** */
/*	Typedefs    															  */
/* ************************************************************************** */

typedef struct s_minishell_ctx
{
	t_automata_lexer	*automata_lexer;
	t_automata_exp  	*automata_expander;
	t_builtin         	**builtins;
	t_btree     		*tokens_bt;
	t_list      		*env;
	char				*input_str;
}	t_minishell_ctx;

# ifndef T_RC
#  define T_RC
typedef enum e_rc
{
	RC_OK,
	RC_NULLPTR,
	RC_NOK
}	t_rc;
# endif

/* ************************************************************************** */
/*	Functions    															  */
/* ************************************************************************** */


/*	Minishell   															  */

/*	Minishell init 															  */

void	minishell_init(t_minishell_ctx *ctx, char **envp);

/*	Interpreter 															  */

t_rc	interpreter_get_input(t_minishell_ctx *ctx);

/*	Test 															  */

int		test_minishell(int argc, char **argv, char **envp);

#endif
