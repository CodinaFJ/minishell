/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:25:08 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/12 21:52:45 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

t_env_var	*environment_variable_parse(char *env_str)
{
	char		**var_strs;
	t_env_var	*env_var;

	var_strs = ft_split(env_str, '=');
	if (var_strs == NULL)
		return (NULL);
	env_var = (t_env_var *) ft_calloc(1, sizeof(t_env_var));
	if (!env_var)
		return (NULL);
	env_var->key = var_strs[0];
	env_var->content = var_strs[1];
	return (env_var);
}

void	environment_variable_print(t_env_var *var)
{
	if (var == NULL)
	{
		ft_printf("(null)\n");
		return ;
	}
	ft_printf("%s = %s\n", var->key, var->content);
}
void	environment_variable_free(void *var)
{
	t_env_var	*env_var;

	if (var == NULL)
		return ;
	env_var = (t_env_var *) var;
	if (env_var->content)
		free(env_var->content);
	if (env_var->key)
		free(env_var->key);
	free(env_var);
}
