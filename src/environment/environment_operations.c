/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:37:20 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/26 12:42:47 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

char	*environment_get(t_list *env, char *key)
{
	t_env_var	*env_var;

	while (env)
	{
		env_var = (t_env_var *)env->content;
		if (env_var == NULL)
			continue ;
		if (ft_strcmp(env_var->key, key) == 0)
			return (ft_strdup(env_var->content));
		env = env->next;
	}
	return (NULL);
}

void	environment_set_keycontent(t_list *env, char *key, char *content)
{
	t_env_var	*env_var;

	if (key == NULL || *key == 0)
		return ;
	while (env)
	{
		env_var = (t_env_var *)env->content;
		if (env_var == NULL)
			continue ;
		if (ft_strcmp(env_var->key, key) == 0)
		{
			free(env_var->content);
			env_var->content = ft_strdup(content);
			return ;
		}
		if (env->next == NULL)
			break ;
		env = env->next;
	}
	env_var = environment_variable_new(key, content);
	if (env_var == NULL)
		return ;
	ft_lstadd_back(&env, ft_lstnew((void *)env_var));
}

void	environment_set_str(t_list *env, char *str)
{
	t_env_var		*env_var;
	const t_env_var	*new_env_var = environment_variable_parse(str);

	if (str == NULL || new_env_var == NULL)
	{
		environment_variable_free((void *) new_env_var);
		return ;
	}
	while (env)
	{
		env_var = (t_env_var *)env->content;
		if (ft_strcmp(env_var->key, new_env_var->key) == 0)
		{
			free(env_var->content);
			env_var->content = new_env_var->content;
			free(new_env_var->key);
			free((void *)new_env_var);
			return ;
		}
		if (env->next == NULL)
			break ;
		env = env->next;
	}
	ft_lstadd_back(&env, ft_lstnew((void *)new_env_var));
}

void	environment_unset(t_list **env, char *key)
{
	t_list		*node;
	t_env_var	*env_var;
	int			i;

	node = *env;
	if (key == NULL || *key == 0)
		return ;
	i = 0;
	while (node)
	{
		env_var = (t_env_var *)node->content;
		i++;
		if (env_var == NULL)
			continue ;
		if (ft_strcmp(env_var->key, key) == 0)
		{
			environment_variable_free((t_env_var *)ft_lst_remove_at(env, i
					- 1));
			return ;
		}
		if (node->next == NULL)
			break ;
		node = node->next;
	}
}
