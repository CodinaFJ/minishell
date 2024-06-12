/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:53:32 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/12 21:50:49 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

t_list	*environment_create(char **envp)
{
	int			i;
	t_list		*env_list;
	t_env_var	*env_var_aux;

	env_list = NULL;
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
		if (env == NULL)
			continue ;
		env_var = (t_env_var *) env->content;
		if (env_var == NULL)
			continue ;
		if (ft_strcmp(env_var->key, key) == 0)
			return (env_var->content);
		env = env->next;
	}
	return (NULL);
}
