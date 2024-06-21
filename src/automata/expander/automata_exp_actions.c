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
    // ft_printf("REMOVE_DOLLAR\n");
    len = ft_strlen(automata->str);
    str_res = (char *) ft_calloc(sizeof(char), len);
    if (str_res == NULL)
        return ;// TODO: I guess we should error here
    ft_strncpy(str_res, automata->str, automata->cursor - 1);
	ft_strcat(str_res, automata->str + automata->cursor);
    // ft_printf("removed dollar: %s\n", str_res);
	free(automata->str);
	automata->str = str_res;
	automata->cursor--;
}

void	extract_variable(t_automata_exp *automata, void *env)
{
    char    *str_res;
    char    *var_key;
    char    *var_content;
    int     var_key_len;
    int     i;

    // ft_printf("EXTRACT_VARIABLE\n");
    i = automata->cursor - 1;
    while (i > 0)
    {
        if (automata->str[i] == '$')
            break ;
		i--;
    }
	// environment_print(env);
    // ft_printf("cursor %d i %d\n", automata->cursor, i);
    var_key_len = automata->cursor - i - 1;
    // ft_printf("Var key len %d\n", var_key_len);
    var_key = (char *) ft_calloc(sizeof(char), var_key_len + 1);
    ft_strncpy(var_key, automata->str + i + 1, var_key_len);
    // ft_printf("step 1 %s\n", var_key);
    str_res = (char *) ft_calloc(sizeof(char), i + 1);
    if (str_res == NULL)
        return ;// TODO: I guess we should error here
    ft_strncpy(str_res, automata->str, i);
	str_res[i] = '\0';
    // ft_printf("step 2 %s. var key: %s\n", str_res, var_key);
	// ft_printf("Getenv var content: %s\n", getenv(var_key));
	var_content =  environment_get(env, var_key);
	free(var_key);
	// ft_printf("Var content: %s\n", var_content);
    str_res = ft_strjoin_free(str_res, var_content, 1);
    str_res = ft_strjoin_free(str_res, automata->str + automata->cursor, 1);
    // ft_printf("extracted variable: %s\n", str_res);
	free(automata->str);
    automata->str = str_res;
	automata->cursor = automata->cursor - var_key_len + ft_strlen(var_content);
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
