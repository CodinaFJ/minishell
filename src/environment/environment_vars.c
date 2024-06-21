/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:25:08 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/18 17:56:02by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

t_env_var	*environment_variable_parse(char *env_str)
{
	t_env_var	*env_var;

	if (env_str == NULL || ft_strchr(env_str, '=') == NULL)
		return (NULL);
	env_var = (t_env_var *) ft_calloc(1, sizeof(t_env_var));
	if (!env_var)
		return (NULL);
	env_var->key = ft_strdup_limit_excluded(env_str, '=');
	if (env_var->key == NULL)
	{
		free(env_var);
		return(NULL);
	}
	env_var->content = ft_strdup(ft_strchr(env_str, '=') + 1);
	if (env_var->content == NULL)
	{
		free(env_var->key);
		free(env_var);
		return (NULL);
	}
	return (env_var);
}

t_env_var	*environment_variable_new(char *key, char *content)
{
	t_env_var	*env_var;

	if (key == NULL || *key == '\0')
		return (NULL);
	env_var = (t_env_var *) ft_calloc(1, sizeof(t_env_var));
	if (!env_var)
		return (NULL);
	env_var->key = ft_strdup(key);
	if (env_var->key == NULL)
	{
		free(env_var);
		return (NULL);
	}
	if (content == NULL)
		env_var->content = ft_strdup("");
	else
		env_var->content = ft_strdup(content);
	if (env_var->content == NULL)
	{
		free(env_var->key);
		free(env_var);
		return (NULL);
	}
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
