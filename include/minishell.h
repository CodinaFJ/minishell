/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:16:43 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/12 21:48:07 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../lib/libft/include/libft.h"
# include "../lib/data_structures_C/include/data_structures.h"
# include "../src/automata/automata_lexer.h"
# include "../src/automata/automata_exp.h"
# include "../src/builtins/builtin.h"
# include "../src/signals/signals.h"
# include "../src/environment/environment.h"
# define SHELL_PROMT "\033[32;1mBashCrandicoot> \033[0;39m"


/* ************************************************************************** */
/*	Typedefs    															  */
/* ************************************************************************** */

typedef struct s_minishell_ctx
{
	t_automata	*automata_lexer;
	t_automata	*automata_expander;
	t_builtin	**builtins;
	t_btree		*tokens_bt;
	t_list		*env;
}	t_minishell_ctx;

/* ************************************************************************** */
/*	Functions    															  */
/* ************************************************************************** */


/*	Minishell   															  */

void	read_command(char *str, t_minishell_ctx *ctx);

/*	Minishell init 															  */

void	automatas_init(t_minishell_ctx *ctx);
void	minishell_init(t_minishell_ctx *ctx, char **envp);

#endif
