/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:16:43 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 18:34:21 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../lib/libft/include/libft.h"
# include "../lib/data_structures_C/include/data_structures.h"
# include "../src/automata/automata.h"
# include "../src/builtins/builtin.h"
# include "../src/signals/signals.h"
# define SHELL_PROMT "\033[32;1mBashCrandicoot> \033[0;39m"


/* ************************************************************************** */
/*	Typedefs    															  */
/* ************************************************************************** */

typedef struct s_minishell_ctx
{
	t_automata	*automata;
	t_builtin	**builtins;
	t_btree		*tokens_bt;
}	t_minishell_ctx;

/* ************************************************************************** */
/*	Functions    															  */
/* ************************************************************************** */


/*	Minishell   															  */

void	read_command(char *str, t_minishell_ctx *ctx);

/*	Minishell init 															  */

void	lexer_init(t_minishell_ctx *ctx);
void	minishell_init(t_minishell_ctx *ctx);

#endif