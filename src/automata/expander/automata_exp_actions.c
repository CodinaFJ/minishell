/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:24:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/11 21:46:48 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_exp.h"

void	end_exp_evaluation(t_automata_exp *automata, void *env)
{
	if (automata->state == E_STRING_VAR)
		extract_variable(automata, env);
	if (automata->errors != NULL && automata->errors[automata->state] != NULL)
		ft_printf("[ERROR] -> %s\n", automata->errors[automata->state]);
}

void	abort_automata(t_automata_exp *automata, void *ctx)
{
	(void)ctx;
	automata->str_len = automata->cursor;
}

void	remove_dollar(t_automata_exp *automata, void *ctx)
{
	char	*str_res;
	int		len;

	(void)ctx;
	len = ft_strlen(automata->str);
	str_res = (char *)ft_calloc(sizeof(char), len);
	if (str_res == NULL)
		minishell_exit_error(ctx, MALLOC_ERR);
	ft_strncpy(str_res, automata->str, automata->cursor - 1);
	ft_strcat(str_res, automata->str + automata->cursor);
	free(automata->str);
	automata->str = str_res;
	automata->cursor--;
}

void	single_char_var(t_automata_exp *automata, void *ctx)
{
	char	*str_res;
	char	var_key;
	char	*str_aux;
	int		i;

	(void)ctx;
	i = automata->cursor - 1;
	var_key = automata->str[automata->cursor];
	str_res = ft_calloc(1, i + 1);
	str_aux = NULL;
	if (str_res == NULL)
		return ;
	ft_strncpy(str_res, automata->str, i);
	if (var_key == '$')
	{
		str_aux = ft_itoa(getpid());
		str_res = ft_strjoin_free(str_res, str_aux, BOTH);
		if (str_res == NULL)
			minishell_exit_error(ctx, MALLOC_ERR);
	}
	str_res 
		= ft_strjoin_free(str_res, automata->str + automata->cursor + 1, FIRST);
	if (str_res)
		minishell_exit_error(ctx, MALLOC_ERR);
	automata->cursor = automata->cursor - 2 + ft_strlen(str_aux);
	automata_exp_resume(automata, str_res);
}
