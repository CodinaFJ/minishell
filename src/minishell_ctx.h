/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_ctx.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:14:42 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/11 20:03:08 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CTX_H
# define MINISHELL_CTX_H
# include "../lib/libft/include/libft.h"
# include "../lib/data_structures_C/include/data_structures.h"
# include "../src/automata/expander/automata_exp.h"
# include "../src/automata/lexer/automata_lexer.h"
# include "../src/builtins/builtin.h"

/* ************************************************************************** */
/*	Typedefs    															  */
/* ************************************************************************** */

# ifndef MINISHELL_CTX
#  define MINISHELL_CTX
typedef struct s_minishell_ctx
{
	struct s_automata_lexer	*automata_lexer;
	struct s_automata_exp  	*automata_expander;
	struct s_builtin        **builtins;
	struct s_btree     		*tokens_bt;
	struct s_list      		*env;
	char				*input_str;
}	t_minishell_ctx;
# endif

void	minishell_ctx_free(t_minishell_ctx *ctx);

#endif