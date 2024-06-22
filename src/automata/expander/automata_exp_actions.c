/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:24:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/21 13:27:19by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_exp.h"

void	remove_quoting(t_automata_exp *automata)
{
	unsigned int	i;

	i = -1;
	while(automata->str[++i])
	{
		if(automata->str[i] == '\'')
		
	}
}

void    end_exp_evaluation(t_automata_exp *automata, void *env)
{
	if (automata->state == E_STRING_VAR)
		extract_variable(automata, env);
	if (automata->errors != NULL && automata->errors[automata->state] != NULL)
	{
		ft_printf("[ERROR] -> %s\n", automata->errors[automata->state]);
	}
}

void	abort_automata(t_automata_exp *automata, void *ctx)
{
	(void) ctx;
	automata->str_len = automata->cursor;
}

void	remove_dollar(t_automata_exp *automata, void *env)
{
    char    *str_res;
    int     len;

	(void) env;
    len = ft_strlen(automata->str);
    str_res = (char *) ft_calloc(sizeof(char), len);
    if (str_res == NULL)
        return ;// TODO: I guess we should error here
    ft_strncpy(str_res, automata->str, automata->cursor - 1);
	ft_strcat(str_res, automata->str + automata->cursor);
	free(automata->str);
	automata->str = str_res;
	automata->cursor--;
}
static int	strr_find_dollar(t_automata_exp *automata)
{
	int	i;

    i = automata->cursor - 1;
    while (i > 0)
    {
        if (automata->str[i] == '$')
            break ;
		i--;
    }
	return (i);
}

char *get_var_key(t_automata_exp *automata, int i)
{
	int		var_key_len;
	char	*var_key;

    var_key_len = automata->cursor - i - 1;
    var_key = (char *) ft_calloc(sizeof(char), var_key_len + 1);
	if (var_key == NULL)
		return (NULL);
    ft_strncpy(var_key, automata->str + i + 1, var_key_len);
	return (var_key);
}

void	extract_variable(t_automata_exp *automata, void *env)
{
    char    *str_res;
    char    *var_key;
    char    *var_content;
    int     i;

	i = strr_find_dollar(automata);
	var_key = get_var_key(automata, i); //TODO Protect this malloc
    str_res = (char *) ft_calloc(sizeof(char), i + 1);
    if (str_res == NULL)
        return ;// TODO: I guess we should error here
    ft_strncpy(str_res, automata->str, i);
	str_res[i] = '\0';
	var_content =  environment_get(env, var_key);
    str_res = ft_strjoin_free(str_res, var_content, 1);
    str_res = ft_strjoin_free(str_res, automata->str + automata->cursor, 1);
	free(automata->str);
    automata->str = str_res;
	automata->cursor = automata->cursor - (ft_strlen(var_key) + 1) + ft_strlen(var_content);
	automata->str_len = ft_strlen(automata->str);
	automata->state = E_PRE_VAR;
	if (automata->str[automata->cursor] == '$')
		automata->state = E_DOLLAR;
	free(var_key);
	if (var_content)
		free(var_content);
}

void		single_char_var(t_automata_exp *automata, void *ctx)
{
    (void) automata;
    (void) ctx;
	// Extract one char variable retroactively, search reverse the dollar and 
	// look for the variable. Here are special cases like $$ or $?, and
	// also $[number] -> this case should just be trated as a variable that
	// is not found.
	// Maybe this whole function could be done in the extract variable function
}
