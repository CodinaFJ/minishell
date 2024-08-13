/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_actions_singlechar_var.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:24:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/27 14:40:21 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*expand_execution_code(t_automata_exp *automata, void *ctx)
{
	char	*str_res;
	char	*str_aux;
	size_t	str_aux_len;

	str_res = ft_calloc(1, automata->cursor);
	if (str_res == NULL)
		minishell_exit_error(ctx, MALLOC_ERR);
	ft_strncpy(str_res, automata->str, automata->cursor - 1);
	str_aux = ft_itoa(((t_minishell_ctx *)ctx)->errsv);
	if (str_aux == NULL)
	{
		free(str_res);
		minishell_exit_error(ctx, MALLOC_ERR);
	}
	str_aux_len = ft_strlen(str_aux);
	str_res = ft_strjoin_free(str_res, str_aux, BOTH);
	if (str_res == NULL)
		minishell_exit_error(ctx, MALLOC_ERR);
	str_res = ft_strjoin_free(str_res, automata->str + automata->cursor + 1,
			FIRST);
	if (str_res == NULL)
		minishell_exit_error(ctx, MALLOC_ERR);
	automata->cursor = automata->cursor - 2 + str_aux_len;
	return (str_res);
}

static char	*expand_pid(t_automata_exp *automata, void *ctx)
{
	char	*str_res;
	char	*str_aux;
	size_t	str_aux_len;

	str_res = ft_calloc(1, automata->cursor);
	if (str_res == NULL)
		minishell_exit_error(ctx, MALLOC_ERR);
	ft_strncpy(str_res, automata->str, automata->cursor - 1);
	str_aux = ft_itoa(((t_minishell_ctx *)ctx)->pid);
	if (str_aux == NULL)
	{
		free(str_res);
		minishell_exit_error(ctx, MALLOC_ERR);
	}
	str_aux_len = ft_strlen(str_aux);
	str_res = ft_strjoin_free(str_res, str_aux, BOTH);
	if (str_res == NULL)
		minishell_exit_error(ctx, MALLOC_ERR);
	str_res = ft_strjoin_free(str_res, automata->str + automata->cursor + 1,
			FIRST);
	if (str_res == NULL)
		minishell_exit_error(ctx, MALLOC_ERR);
	automata->cursor = automata->cursor - 2 + str_aux_len;
	return (str_res);
}

void	single_char_var(t_automata_exp *automata, void *ctx)
{
	char	*str_res;
	char	var_key;

	var_key = automata->str[automata->cursor];
	str_res = NULL;
	if (var_key == '$')
		str_res = expand_pid(automata, ctx);
	else if (var_key == '?')
		str_res = expand_execution_code(automata, ctx);
	else
	{
		str_res = ft_calloc(1, automata->cursor);
		if (str_res == NULL)
			minishell_exit_error(ctx, MALLOC_ERR);
		ft_strncpy(str_res, automata->str, automata->cursor - 1);
		str_res = ft_strjoin_free(str_res, automata->str + automata->cursor + 1,
				FIRST);
		automata->cursor = automata->cursor - 2;
		if (str_res == NULL)
			minishell_exit_error(ctx, MALLOC_ERR);
	}
	automata_exp_resume(automata, str_res);
}
