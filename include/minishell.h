/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:16:43 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/11 22:16:33 by jcodina-         ###   ########.fr       */
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

t_rc	interpreter_get_line(t_minishell_ctx *ctx);

/*	Test 															  */

int		test_minishell(int argc, char **argv, char **envp);

#endif
