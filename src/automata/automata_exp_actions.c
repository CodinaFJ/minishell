/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:24:10 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/13 00:47:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automata_exp.h"
#include "libft/include/ft_printf.h"
#include "libft/include/get_next_line.h"
#include "libft/include/libft.h"

// char	*expand_var_len(char *str, int var_len)
// {

// }

void	end_exp_evaluation(t_automata *automata, void *ctx)
{
	//char	*new_str;
	//char	*old_str;

	(void) ctx;
	//old_str = (char *) ctx;
	// FUNCTION TO SUBSTITUTE A STRING INSIDE OTHER STRING
	// ft_str_subst(char* original_str, char* string_to_find, char* string_to_insert);
	write(1, automata->str, automata->str_len);
	ft_printf("\n");
	if (automata->errors != NULL && automata->errors[automata->state] != NULL)
	{
		ft_printf("[ERROR] -> %s\n", automata->errors[automata->state]);
		return ;
	}
}

void	abort_automata(t_automata *automata, void *ctx)
{
	(void) ctx;
	automata->str_len = automata->cursor;
}

void		remove_dollar(t_automata *automata, void *ctx)
{
    char    *str_aux;
    char    **str_og;
    int     len;

    ft_printf("REMOVE_DOLLAR\n");
    str_og = (char **) ctx;
    len = ft_strlen(*str_og);
    str_aux = (char *) ft_calloc(sizeof(char), len - 1);
    if (str_aux == NULL)
        return ;// TODO: I guess we should error here
    ft_strncpy(str_aux, *str_og, automata->cursor - 1);
    ft_strcat(str_aux, *str_og + automata->cursor);
    free(*str_og);
    *str_og = str_aux;
    ft_printf("removed dollar: %s\n", str_aux);
}

void		extract_variable(t_automata *automata, void *ctx)
{
    char    *str_aux;
    char    **str_og;
    char    *var_key;
    int     var_key_len;
    int     i;

    ft_printf("EXTRACT_VARIABLE\n");
    str_og = (char **) ctx;
    i = automata->cursor;
    while (--i >= 0)
    {
        if ((*str_og)[i] == '$')
            break ;
    }
    ft_printf("cursor %d i %d\n", automata->cursor, i);
    var_key_len = automata->cursor - i - 1;
    ft_printf("Var key len %d\n", var_key_len);
    var_key = (char *) ft_calloc(sizeof(char), var_key_len + 1);
    ft_strncpy(var_key, *str_og + i + 1, var_key_len);
    ft_printf("step 1 %s\n", var_key);
    str_aux = (char *) ft_calloc(sizeof(char), i);
    if (str_aux == NULL)
        return ;// TODO: I guess we should error here
    ft_strncpy(str_aux, *str_og, i);
    ft_printf("step 2 %s\n", str_aux);
    str_aux = ft_strjoin_gnl(str_aux, getenv(var_key));
    str_aux = ft_strjoin_gnl(str_aux, *str_og + automata->cursor);
    free(*str_og);
    *str_og = str_aux;
    ft_printf("expanded variable %s\n", str_aux);
}

void		single_char_var(t_automata *automata, void *ctx)
{
    (void) automata;
    (void) ctx;
	// Extract one char variable retroactively, search reverse the dollar and 
	// look for the variable. Here are special cases like $$ or $?, and
	// also $[number] -> this case should just be trated as a variable that
	// is not found.
	// Maybe this whole function could be done in the extract variable function
}
