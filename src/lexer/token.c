/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:37:42 by jcodina-          #+#    #+#             */
/*   Updated: 2024/08/27 18:17:32 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*token_new(t_token_id id, void *content)
{
	t_token	*token;

	if (id != COMMAND && id != OPERATOR)
		return (NULL);
	token = ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->id = id;
	token->content = (t_token_content *) content;	
	return (token);
}
void	token_print(void *token)
{
	t_token	*_token;

	_token = (t_token *) token;
	if (token == NULL)
		return ;
	printf("\n-----TOKEN-----\n");
	if (_token->id == COMMAND &&  _token->content != NULL)
	{
		printf("ID [COMMAND]\n");
		command_print((t_command *) _token->content);
	}
	else if (_token->id == OPERATOR &&  _token->content != NULL)
	{
		printf("ID [OPERATOR]\n");
		operator_print((t_operator *) _token->content);	
	}
}

void	token_free(void *token)
{
	t_token	*_token;
	
	if (token == NULL)
		return ;
	_token = (t_token *) token;
	if (_token->content != NULL)
	{
		if (_token->id == COMMAND)
		{
			command_free((t_command *) _token->content);
			_token->content = NULL;
		}
		else if (_token->id == OPERATOR)
		{
			operator_free((t_operator *) _token->content);
			_token->content = NULL;	
		}
	}
	free(_token);
}
