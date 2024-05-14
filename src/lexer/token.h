/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:26:33 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 20:50:26 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "../../lib/libft/include/libft.h"
# include "../../lib/data_structures_C/include/data_structures.h"
# define N_ARGS 10

typedef enum e_token_id
{
	COMMAND,
	OPERATOR
}	t_token_id;

typedef struct s_operator
{
	char	*op;
}	t_operator;

t_operator	*operator_new(char *op);
void		operator_print(t_operator *optr);
void		operator_free(t_operator *optr);

typedef struct s_command
{
	char	*command;
	char	**args;	
}	t_command;

t_command	*command_new(char *command, int args);
void		command_print(t_command *command);
void		command_free(t_command *command);

typedef union u_token_content
{
	struct s_command	command;
	struct s_operator	op;
}	t_token_content;

typedef struct s_token
{
	t_token_content	*content;	
	t_token_id		id;
}	t_token;

t_token	*token_new(t_token_id id, void *content);
void	token_print(void *token);
void	token_free(void *token);

void	token_append_arg(t_token *token, char *arg);
void	command_append_arg(t_command *command, char *arg);

void	tokenbt_insert_oprtr(t_btree *token_bt, char *token_str);
void	tokenbt_insert_comm_word(t_btree *token_bt, char *token_str);

#endif