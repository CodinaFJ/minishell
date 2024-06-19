/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:53:32 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/17 20:18:21 jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

t_list	*environment_create(char **envp)
{
	int			i;
	t_list		*env_list;
	t_env_var	*env_var_aux;

	if (envp == NULL)
		return (NULL);
	env_list = NULL;
	env_var_aux = NULL;
	i = -1;
	while(envp[++i])
	{
		env_var_aux = environment_variable_parse(envp[i]);
		if (env_var_aux == NULL)
			continue ;
		ft_lstadd_front(&env_list, ft_lstnew((void *) env_var_aux));        
	}
	return (env_list);
}

void	environment_print(t_list *env_list)
{
	while (env_list)
	{
		if (env_list == NULL)
			continue; ;
		environment_variable_print(env_list->content);
		env_list = env_list->next;
	}
}

char	*environment_get(t_list *env ,char *key)
{
	t_env_var	*env_var;
	
	while (env)
	{
		env_var = (t_env_var *) env->content;
		if (env_var == NULL)
			continue ;
		if (ft_strcmp(env_var->key, key) == 0)
			return (ft_strdup(env_var->content));
		env = env->next;
	}
	return (NULL);
}

void	environment_set(t_list *env, char *key, char *content)
{
	t_env_var	*env_var;

	if (key == NULL || *key == 0)
		return ;
	while (env)
	{
		env_var = (t_env_var *) env->content;
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
		env_var = (t_env_var *) node->content;
		i++;
		if (env_var == NULL)
			continue ;
		if (ft_strcmp(env_var->key, key) == 0)
		{
			environment_variable_free((t_env_var *) ft_lst_remove_at(env, i - 1));
			return ;
		}
		if (node->next == NULL)
			break ;
		node = node->next;
	}
}